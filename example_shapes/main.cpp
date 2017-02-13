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
#include <string>

using namespace std;
using namespace simpson;

static_assert(is_arithmetic<shape_t>::value, "shape_t  is not arithmetic");
static_assert(is_floating_point<shape_t>::value, "shape_t  is not floating point");

using StreamablePtrs = vector<ISerializableUniquePtr>;

void writeToFile(const StreamablePtrs &shapes, const string &fileName)
{
    ofstream outFile(fileName);
    if(!outFile.is_open())
        throw std::runtime_error("can't open the output file");
    for(const auto &shape : shapes)
        outFile << *shape;
    outFile.close();
}

StreamablePtrs readFromFile(const string &fileName)
{
    // loading shapes
    ifstream inFile(fileName);
    if(!inFile.is_open())
        throw std::runtime_error("can't open the input file");
    StreamablePtrs shapes;
    StreamDeserializer deserializer(inFile);
    while(!inFile.eof())
        shapes.push_back(ISerializableUniquePtr(deserializer.deserialize()));
    inFile.close();
    return shapes;
}

int main(int argc, char *argv[])
{
    try
    {
        if(argc == 2)
        {
            // generating N random shapes and writing them to a file
            StreamablePtrs shapes;
            srand(time(nullptr));
            for(int i = 0; i < 100; i++)
            {
                switch(rand() % 4)
                {
                case 0:
                    shapes.push_back(make_unique<Circle>(ShapePos2D(rand(), rand()), rand()));
                    break;
                case 1:
                    shapes.push_back(make_unique<RegularPolygon>(ShapePos2D(rand(), rand()), rand(), rand()));
                    break;
                case 2:
                    shapes.push_back(make_unique<EquilateralTriangle>(ShapePos2D(rand(), rand()), rand()));
                    break;
                case 3:
                    shapes.push_back(make_unique<Square>(ShapePos2D(rand(), rand()), rand()));
                    break;
                }
            }
            writeToFile(shapes, argv[1]);
        }
        else if(argc == 3)
        {
            // loading shapes
            StreamablePtrs shapes = readFromFile(argv[1]);
            // saving shapes
            writeToFile(shapes, argv[2]);
        }
        else
        {
            cout << "Usage:\n";
            cout << "Scenario 1\n[outputFile] - to generate 100 random shapes and write them to the file\n";
            cout << "Scenario 2\n[inputFile] [outputFile] - to load figures from the input file and save "
                    "them to the output file\n";
        }
    }
    catch(const std::runtime_error &error)
    {
        cout << error.what() << endl;
        return 1;
    }
    return 0;
}
