#include "Circle.h"

#include "EquilateralTriangle.h"
#include "Rectangle.h"
#include "RegularPolygon.h"
#include "Shape.h"
#include "Square.h"

// serialization
#include <SerializationToStream.h>

#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <vector>

static_assert(std::is_arithmetic<shape_t>::value, "shape_t  is not arithmetic");
static_assert(std::is_floating_point<shape_t>::value, "shape_t  is not floating point");

using StreamablePtrs = std::vector<ISerializableUniquePtr>;

void writeToFile(const StreamablePtrs &shapes, const char *fileName)
{
    std::ofstream outFile(fileName);
    if(!outFile.is_open())
    {
        std::cout << "can't open the output file\n";
        return;
    }
    for(size_t i = 0; i < shapes.size(); ++i)
    {
        outFile << *shapes[i];
    }
    outFile.close();
}

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        // generating N random shapes and writing them to a file
        StreamablePtrs shapes;
        srand(std::time(NULL));
        for(int i = 0; i < 100; i++)
        {
            switch(rand() % 4)
            {
            case 0:
                shapes.push_back(ISerializableUniquePtr(new Circle(ShapePos2D(rand(), rand()), rand())));
                break;
            case 1:
                shapes.push_back(
                    ISerializableUniquePtr(new RegularPolygon(ShapePos2D(rand(), rand()), rand(), rand())));
                break;
            case 2:
                shapes.push_back(ISerializableUniquePtr(new EquilateralTriangle(ShapePos2D(rand(), rand()), rand())));
                break;
            case 3:
                shapes.push_back(ISerializableUniquePtr(new Square(ShapePos2D(rand(), rand()), rand())));
                break;
            }
        }
        writeToFile(shapes, argv[1]);
    }
    else if(argc == 3)
    {
        // loading shapes
        StreamablePtrs shapes;
        std::ifstream inFile(argv[1]);
        if(!inFile.is_open())
        {
            std::cout << "can't open the input file\n";
            return 1;
        }
        StreamDeserializer deserializer(inFile);
        while(!inFile.eof())
            shapes.push_back(ISerializableUniquePtr(deserializer.deserialize()));
        inFile.close();

        // saving shapes
        writeToFile(shapes, argv[2]);
    }
    else
    {
        std::cout << "Usage:\n";
        std::cout << "Scenario 1\n[outputFile] - to generate 100 random shapes and write them to the file\n";
        std::cout << "Scenario 2\n[inputFile] [outputFile] - to load figures from the input file and save "
                     "them to the output file\n";
    }

    return 0;
}
