#include "obj3D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* obj3D::CreateTrack(
    const std::string& name,
    glm::vec3 leftBottomCorner)
{
    glm::vec3 startPoint = leftBottomCorner;
    glm::vec3 color = glm::vec3(0.1f, 0.1f, 0.1f);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(startPoint + glm::vec3(5.06f, 0, -1.33f), color),
        VertexFormat(startPoint + glm::vec3(9.9f, 0, -3.22f), color),
        VertexFormat(startPoint + glm::vec3(13.95f, 0, -5.19f), color),
        VertexFormat(startPoint + glm::vec3(17.63f, 0, -6.63f), color),
        VertexFormat(startPoint + glm::vec3(21.58f, 0, -7.62f), color),
        VertexFormat(startPoint + glm::vec3(25.44f, 0, -7.44f), color),
        VertexFormat(startPoint + glm::vec3(29.03f, 0, -6.27f), color),
        VertexFormat(startPoint + glm::vec3(31.28f, 0, -4.74f), color),
        VertexFormat(startPoint + glm::vec3(33.25f, 0, -2.14f), color),
        VertexFormat(startPoint + glm::vec3(34.15f, 0, 0.99f), color),
        VertexFormat(startPoint + glm::vec3(34.33f, 0, 4.62f), color),
        VertexFormat(startPoint + glm::vec3(33.25f, 0, 7.1f), color),
        VertexFormat(startPoint + glm::vec3(31.45f, 0, 8.63f), color),
        VertexFormat(startPoint + glm::vec3(28.94f, 0, 9.7f), color),
        VertexFormat(startPoint + glm::vec3(25.96f, 0, 10.24f), color),
        VertexFormat(startPoint + glm::vec3(23.82f, 0, 12.04f), color),
        VertexFormat(startPoint + glm::vec3(22.39f, 0, 14.37f), color),
        VertexFormat(startPoint + glm::vec3(22.12f, 0, 17.16f), color),
        VertexFormat(startPoint + glm::vec3(23.01f, 0, 20.03f), color),
        VertexFormat(startPoint + glm::vec3(25.44f, 0, 22.1f), color),
        VertexFormat(startPoint + glm::vec3(27.95f, 0, 23.08f), color),
        VertexFormat(startPoint + glm::vec3(31.9f, 0, 23.35f), color),
        VertexFormat(startPoint + glm::vec3(36.84f, 0, 23.08f), color),
        VertexFormat(startPoint + glm::vec3(39.9f, 0, 21.83f), color),
        VertexFormat(startPoint + glm::vec3(41.87f, 0, 19.22f), color),
        VertexFormat(startPoint + glm::vec3(43.94f, 0, 17.07f), color),
        VertexFormat(startPoint + glm::vec3(45.0f, 0, 15.0f), color),
        VertexFormat(startPoint + glm::vec3(46.16f, 0, 13.21f), color),
        VertexFormat(startPoint + glm::vec3(47.98f, 0, 11.59f), color),
        VertexFormat(startPoint + glm::vec3(50.67f, 0, 11.05f), color),
        VertexFormat(startPoint + glm::vec3(54.44f, 0, 12.04f), color),
        VertexFormat(startPoint + glm::vec3(58.12f, 0, 10.86f), color),
        VertexFormat(startPoint + glm::vec3(61.89f, 0, 12.22f), color),
        VertexFormat(startPoint + glm::vec3(66.38f, 0, 10.51f), color),
        VertexFormat(startPoint + glm::vec3(69.51f, 0, 12.26f), color),
        VertexFormat(startPoint + glm::vec3(72.32f, 0, 11.58f), color),
        VertexFormat(startPoint + glm::vec3(75.0f, 0, 10.0f), color),
        VertexFormat(startPoint + glm::vec3(78.51f, 0, 10.87f), color),
        VertexFormat(startPoint + glm::vec3(80.93f, 0, 12.67f), color),
        VertexFormat(startPoint + glm::vec3(81.29f, 0, 15.36f), color),
        VertexFormat(startPoint + glm::vec3(79.94f, 0, 17.25f), color),
        VertexFormat(startPoint + glm::vec3(78.06f, 0, 18.5f), color),
        VertexFormat(startPoint + glm::vec3(75.36f, 0, 19.22f), color),
        VertexFormat(startPoint + glm::vec3(71.14f, 0, 21.11f), color),
        VertexFormat(startPoint + glm::vec3(69.16f, 0, 20.51f), color),
        VertexFormat(startPoint + glm::vec3(67.24f, 0, 19.37f), color),
        VertexFormat(startPoint + glm::vec3(65.05f, 0, 18.5f), color),
        VertexFormat(startPoint + glm::vec3(62.86f, 0, 19.37f), color),
        VertexFormat(startPoint + glm::vec3(59.79f, 0, 22.0f), color),
        VertexFormat(startPoint + glm::vec3(59.97f, 0, 24.19f), color),
        VertexFormat(startPoint + glm::vec3(59.27f, 0, 26.29f), color),
        VertexFormat(startPoint + glm::vec3(57.4f, 0, 30.81f), color),
        VertexFormat(startPoint + glm::vec3(55.94f, 0, 32.07f), color),
        VertexFormat(startPoint + glm::vec3(53.49f, 0, 33.21f), color),
        VertexFormat(startPoint + glm::vec3(51.04f, 0, 32.07f), color),
        VertexFormat(startPoint + glm::vec3(48.76f, 0, 33.47f), color),
        VertexFormat(startPoint + glm::vec3(45.0f, 0, 35.0f), color),
        VertexFormat(startPoint + glm::vec3(40.52f, 0, 36.64f), color),
        VertexFormat(startPoint + glm::vec3(38.95f, 0, 38.2f), color),
        VertexFormat(startPoint + glm::vec3(38.25f, 0, 40.13f), color),
        VertexFormat(startPoint + glm::vec3(37.02f, 0, 43.38f), color),
        VertexFormat(startPoint + glm::vec3(36.06f, 0, 45.47f), color),
        VertexFormat(startPoint + glm::vec3(33.96f, 0, 46.96f), color),
        VertexFormat(startPoint + glm::vec3(31.42f, 0, 47.57f), color),
        VertexFormat(startPoint + glm::vec3(28.88f, 0, 47.22f), color),
        VertexFormat(startPoint + glm::vec3(27.31f, 0, 46.17f), color),
        VertexFormat(startPoint + glm::vec3(26.69f, 0, 43.98f), color),
        VertexFormat(startPoint + glm::vec3(28.44f, 0, 39.16f), color),
        VertexFormat(startPoint + glm::vec3(29.76f, 0, 37.41f), color),
        VertexFormat(startPoint + glm::vec3(29.96f, 0, 35.65f), color),
        VertexFormat(startPoint + glm::vec3(29.43f, 0, 33.86f), color),
        VertexFormat(startPoint + glm::vec3(28.04f, 0, 33.23f), color),
        VertexFormat(startPoint + glm::vec3(25.98f, 0, 33.05f), color),
        VertexFormat(startPoint + glm::vec3(23.96f, 0, 34.11f), color),
        VertexFormat(startPoint + glm::vec3(22.11f, 0, 35.57f), color),
        VertexFormat(startPoint + glm::vec3(20.0f, 0, 40.0f), color),
        VertexFormat(startPoint + glm::vec3(18.43f, 0, 42.38f), color),
        VertexFormat(startPoint + glm::vec3(16.3f, 0, 43.73f), color),
        VertexFormat(startPoint + glm::vec3(10.0f, 0, 45.0f), color),
        VertexFormat(startPoint + glm::vec3(8.02f, 0, 44.43f), color),
        VertexFormat(startPoint + glm::vec3(7.39f, 0, 42.7f), color),
        VertexFormat(startPoint + glm::vec3(7.31f, 0, 40.81f), color),
        VertexFormat(startPoint + glm::vec3(8.34f, 0, 35.53f), color),
        VertexFormat(startPoint + glm::vec3(9.36f, 0, 33.63f), color),
        VertexFormat(startPoint + glm::vec3(8.67f, 0, 31.66f), color),
        VertexFormat(startPoint + glm::vec3(8.65f, 0, 30.09f), color),
        VertexFormat(startPoint + glm::vec3(7.08f, 0, 28.98f), color),
        VertexFormat(startPoint + glm::vec3(4.79f, 0, 29.06f), color),
        VertexFormat(startPoint + glm::vec3(1.89f, 0, 30.05f), color),
        VertexFormat(startPoint + glm::vec3(0.37f, 0, 32.06f), color),
        VertexFormat(startPoint + glm::vec3(-1.27f, 0, 33.32f), color),
        VertexFormat(startPoint + glm::vec3(-4.82f, 0, 35.84f), color),
        VertexFormat(startPoint + glm::vec3(-6.79f, 0, 37.1f), color),
        VertexFormat(startPoint + glm::vec3(-8.57f, 0, 36.19f), color),
        VertexFormat(startPoint + glm::vec3(-9.38f, 0, 34.48f), color),
        VertexFormat(startPoint + glm::vec3(-7.97f, 0, 30.48f), color),
        VertexFormat(startPoint + glm::vec3(-8.67f, 0, 28.74f), color),
        VertexFormat(startPoint + glm::vec3(-13.11f, 0, 27.63f), color),
        VertexFormat(startPoint + glm::vec3(-14.83f, 0, 28.19f), color),
        VertexFormat(startPoint + glm::vec3(-16.53f, 0, 29.54f), color),
        VertexFormat(startPoint + glm::vec3(-18.22f, 0, 30.32f), color),
        VertexFormat(startPoint + glm::vec3(-20.0f, 0, 30.0f), color),
        VertexFormat(startPoint + glm::vec3(-21.06f, 0, 27.88f), color),
        VertexFormat(startPoint + glm::vec3(-20.35f, 0, 26.14f), color),
        VertexFormat(startPoint + glm::vec3(-18.75f, 0, 24.81f), color),
        VertexFormat(startPoint + glm::vec3(-18.06f, 0, 22.83f), color),
        VertexFormat(startPoint + glm::vec3(-18.69f, 0, 21.02f), color),
        VertexFormat(startPoint + glm::vec3(-18.46f, 0, 18.89f), color),
        VertexFormat(startPoint + glm::vec3(-16.41f, 0, 17.87f), color),
        VertexFormat(startPoint + glm::vec3(-13.57f, 0, 17.16f), color),
        VertexFormat(startPoint + glm::vec3(-8.49f, 0, 17.29f), color),
        VertexFormat(startPoint + glm::vec3(-6.24f, 0, 16.29f), color),
        VertexFormat(startPoint + glm::vec3(-5.63f, 0, 14.66f), color),
        VertexFormat(startPoint + glm::vec3(-5.73f, 0, 12.98f), color),
        VertexFormat(startPoint + glm::vec3(-6.82f, 0, 11.74f), color),
        VertexFormat(startPoint + glm::vec3(-10.0f, 0, 10.0f), color),
        VertexFormat(startPoint + glm::vec3(-12.29f, 0, 10.24f), color),
        VertexFormat(startPoint + glm::vec3(-15.04f, 0, 10.89f), color),
        VertexFormat(startPoint + glm::vec3(-20.3f, 0, 13.72f), color),
        VertexFormat(startPoint + glm::vec3(-23.61f, 0, 13.96f), color),
        VertexFormat(startPoint + glm::vec3(-26.69f, 0, 12.91f), color),
        VertexFormat(startPoint + glm::vec3(-28.55f, 0, 11.13f), color),
        VertexFormat(startPoint + glm::vec3(-28.87f, 0, 9.19f), color),
        VertexFormat(startPoint + glm::vec3(-27.17f, 0, 5.79f), color),
        VertexFormat(startPoint + glm::vec3(-26.53f, 0, 4.23f), color),
        VertexFormat(startPoint + glm::vec3(-26.55f, 0, 0.52f), color),
        VertexFormat(startPoint + glm::vec3(-25.78f, 0, -2.30f), color),
        VertexFormat(startPoint + glm::vec3(-24.15f, 0, -4.17f), color),
        VertexFormat(startPoint + glm::vec3(-20.43f, 0, -5.61f), color),
        VertexFormat(startPoint + glm::vec3(-18.78f, 0, -6.24f), color),
        VertexFormat(startPoint + glm::vec3(-17.46f, 0, -5.43f), color),
        VertexFormat(startPoint + glm::vec3(-13.1f, 0, -1.52f), color),
        VertexFormat(startPoint + glm::vec3(-11.68f, 0, -0.17f), color),
        VertexFormat(startPoint + glm::vec3(-9.12f, 0, 0.81f), color),
        VertexFormat(startPoint + glm::vec3(-6.07f, 0, 0.67f), color),
        VertexFormat(startPoint + glm::vec3(-3.29f, 0, 0.03f), color)
    };

    Mesh* track = new Mesh(name);

    glm::vec3 up = glm::vec3(0, 1, 0);
    std::vector<VertexFormat> new_vertices;
    glm::vec3 dist, p;
    for (int i = 0; i < vertices.size() - 1; i++)
    {
        dist = vertices[i + 1].position - vertices[i].position;
        p = normalize(glm::cross(dist, up));
        new_vertices.push_back(VertexFormat(vertices[i].position - 1.5f * p, color));
        new_vertices.push_back(VertexFormat(vertices[i].position + 1.5f * p, color));
    }
    dist = vertices[0].position - vertices[vertices.size() - 1].position;
    p = normalize(glm::cross(dist, up));
    new_vertices.push_back(VertexFormat(vertices[vertices.size() - 1].position - 1.5f * p, color));
    new_vertices.push_back(VertexFormat(vertices[vertices.size() - 1].position + 1.5f * p, color));

    std::vector<unsigned int> indices;
    for (int i = 0; i < new_vertices.size() - 2; i++)
    {
        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }
    indices.push_back(new_vertices.size() - 1);
    indices.push_back(new_vertices.size() - 2);
    indices.push_back(0);
    indices.push_back(new_vertices.size() - 1);
    indices.push_back(0);
    indices.push_back(1);
    
    track->InitFromData(new_vertices, indices);
    return track;
}

Mesh* obj3D::CreateGrass(
    const std::string& name,
    glm::vec3 leftBottomCorner)
{
    glm::vec3 startPoint = leftBottomCorner;
    glm::vec3 color = glm::vec3(0.341f, 0.69f, 0.035f);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint, color),
        VertexFormat(glm::vec3(140, 0, 0), color),
        VertexFormat(glm::vec3(140, 0, 80), color),
        VertexFormat(glm::vec3(0, 0, 80), color)
    };

    Mesh* grass = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 2, 3, 0 };
    grass->InitFromData(vertices, indices);
    return grass;
}

Mesh* obj3D::CreateSimpleCar(
    const std::string& name,
    glm::vec3 leftBottomCorner)
{
    glm::vec3 startPoint = leftBottomCorner;
    glm::vec3 carColor = glm::vec3(0.258f, 0.192f, 0.87f);
    glm::vec3 carGlass = glm::vec3(0.227f, 0.239f, 0.223f);
    glm::vec3 carBrakes = glm::vec3(1, 0, 0);
    glm::vec3 carLights = glm::vec3(1, 0.95f, 0.95f);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(startPoint + glm::vec3(-1.5f, 0, 0), carColor),            //A(0)
        VertexFormat(startPoint + glm::vec3(1.5f, 0, 0), carColor),             //B(1)
        VertexFormat(startPoint + glm::vec3(-1.5f, 0.8f, 0), carColor),         //C(2)
        VertexFormat(startPoint + glm::vec3(1.5f, 0.8f, 0), carColor),          //D(3)
        VertexFormat(startPoint + glm::vec3(-1.5f, 1, 1), carColor),            //E(4)
        VertexFormat(startPoint + glm::vec3(1.5f, 1, 1), carColor),             //F(5)
        VertexFormat(startPoint + glm::vec3(-1.5f, 2, 1.5f), carColor),         //G(6)
        VertexFormat(startPoint + glm::vec3(1.5f, 2, 1.5f), carColor),          //H(7)
        VertexFormat(startPoint + glm::vec3(-1.5f, 2, 4), carColor),            //I(8)
        VertexFormat(startPoint + glm::vec3(1.5f, 2, 4), carColor),             //J(9)
        VertexFormat(startPoint + glm::vec3(-1.5f, 1, 5), carColor),            //K(10)
        VertexFormat(startPoint + glm::vec3(1.5f, 1, 5), carColor),             //L(11)
        VertexFormat(startPoint + glm::vec3(-1.5f, 0.8f, 6), carColor),         //M(12)
        VertexFormat(startPoint + glm::vec3(1.5f, 0.8f, 6), carColor),          //N(13)
        VertexFormat(startPoint + glm::vec3(-1.5f, 0, 6), carColor),            //O(14)
        VertexFormat(startPoint + glm::vec3(1.5f, 0, 6), carColor)  ,           //P(15)
        VertexFormat(startPoint + glm::vec3(-1.5f, 1, 1), carGlass),            //E'(16)
        VertexFormat(startPoint + glm::vec3(1.5f, 1, 1), carGlass),             //F'(17)
        VertexFormat(startPoint + glm::vec3(-1.5f, 2, 1.5f), carGlass),         //G'(18)
        VertexFormat(startPoint + glm::vec3(1.5f, 2, 1.5f), carGlass),          //H'(19)
        VertexFormat(startPoint + glm::vec3(-1.5f, 2, 4), carGlass),            //I'(20)
        VertexFormat(startPoint + glm::vec3(1.5f, 2, 4), carGlass),             //J'(21)
        VertexFormat(startPoint + glm::vec3(-1.5f, 1, 5), carGlass),            //K'(22)
        VertexFormat(startPoint + glm::vec3(1.5f, 1, 5), carGlass),             //L'(23)
        VertexFormat(startPoint + glm::vec3(1.2f, 0.75f, -0.01f), carBrakes),   //Q(24)
        VertexFormat(startPoint + glm::vec3(1.2f, 0.55f, -0.01f), carBrakes),   //R(25)
        VertexFormat(startPoint + glm::vec3(0.7f, 0.55f, -0.01f), carBrakes),   //S(26)
        VertexFormat(startPoint + glm::vec3(0.7f, 0.75f, -0.01f), carBrakes),   //T(27)
        VertexFormat(startPoint + glm::vec3(-1.2f, 0.55f, -0.01f), carBrakes),  //U(28)
        VertexFormat(startPoint + glm::vec3(-1.2f, 0.75f, -0.01f), carBrakes),  //V(29)
        VertexFormat(startPoint + glm::vec3(-0.7f, 0.75f, -0.01f), carBrakes),  //W(30)
        VertexFormat(startPoint + glm::vec3(-0.7f, 0.55f, -0.01f), carBrakes),  //Z(31)
        VertexFormat(startPoint + glm::vec3(-1.3f, 0.7f, 6.01f), carLights),    //A1(32)
        VertexFormat(startPoint + glm::vec3(-1.3f, 0.55f, 6.01f), carLights),   //B1(33)
        VertexFormat(startPoint + glm::vec3(-0.6f, 0.7f, 6.01f), carLights),    //C1(34)
        VertexFormat(startPoint + glm::vec3(-0.6f, 0.55f, 6.01f), carLights),   //D1(35)
        VertexFormat(startPoint + glm::vec3(1.3f, 0.7f, 6.01f), carLights),     //E1(36)
        VertexFormat(startPoint + glm::vec3(1.3f, 0.55f, 6.01f), carLights),    //F1(37)
        VertexFormat(startPoint + glm::vec3(0.6f, 0.7f, 6.01f), carLights),     //G1(38)
        VertexFormat(startPoint + glm::vec3(0.6f, 0.55f, 6.01f), carLights)     //H1(39)
    };

    Mesh* car = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        1, 0, 2,    //B A C
        2, 3, 1,    //C D B
        3, 2, 5,    //D C F
        2, 4, 5,    //C E F
        17, 16, 19, //F' E' H'
        16, 18, 19, //E' G' H'
        7, 6, 9,    //H G J
        6, 8, 9,    //G I J
        21, 22, 20, //J' K' I'
        21, 23, 22, //J' L' K'
        11, 10, 12, //L K M
        11, 12, 13, //L M N
        13, 15, 14, //N P O
        14, 12, 13, //O M N
        1, 0, 14,   //B A O
        14, 15, 1,  //O P B
        2, 0, 14,   //C A O
        3, 1, 15,   //D B P
        16, 20, 18, //E' I' G'
        22, 20, 16, //K' I' E'
        17, 21, 19, //F' J' H'
        23, 21, 17, //L' J' F'
        15, 11, 3,  //P L D
        3, 5, 11,   //D F L
        15, 13, 11, //P N L
        14, 12, 10, //O M K
        2, 10, 4,   //C K E
        14, 2, 10,  //O C K
        26, 27, 25, //S T R
        25, 27, 24, //R T Q
        30, 31, 29, //W Z V
        28, 29, 31, //U V Z
        32, 33, 34, //A1 B1 C1
        33, 35, 34, //B1 D1 C1
        39, 36, 38, //H1 E1 G1
        39, 37, 36  //H1 F1 E1
    };

    car->InitFromData(vertices, indices);
    return car;
}

Mesh* obj3D::CreateTree(
    const std::string& name,
    glm::vec3 centerTree)
{
    glm::vec3 leaves = glm::vec3(0.207f, 0.349f, 0.121f);
    glm::vec3 trunk = glm::vec3(0.305f, 0.309f, 0.317f);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(centerTree + glm::vec3(-0.5f, 0,-0.5f), trunk),    //A(0)
        VertexFormat(centerTree + glm::vec3(-0.5f, 0,0.5f), trunk),     //B(1)
        VertexFormat(centerTree + glm::vec3(0.5f, 0,0.5f), trunk),      //C(2)
        VertexFormat(centerTree + glm::vec3(0.5f, 0,-0.5f), trunk),     //D(3)
        VertexFormat(centerTree + glm::vec3(-0.5f, 3,-0.5f), trunk),    //E(4)
        VertexFormat(centerTree + glm::vec3(-0.5f, 3,0.5f), trunk),     //F(5)
        VertexFormat(centerTree + glm::vec3(0.5f, 3,0.5f), trunk),      //G(6)
        VertexFormat(centerTree + glm::vec3(0.5f, 3,-0.5f), trunk),     //H(7)
        VertexFormat(centerTree + glm::vec3(1.5f, 3,1.5f), leaves),     //I(8)
        VertexFormat(centerTree + glm::vec3(1.5f, 3,-1.5f), leaves),    //J(9)
        VertexFormat(centerTree + glm::vec3(-1.5f, 3,1.5f), leaves),    //K(10)
        VertexFormat(centerTree + glm::vec3(-1.5f, 3,-1.5f), leaves),   //L(11)
        VertexFormat(centerTree + glm::vec3(0, 8, 0), leaves)           //M(12)
    };

    Mesh* tree = new Mesh(name);
    std::vector<unsigned int> indices = {
        3, 0, 1,    //D A B
        1, 2, 3,    //B C D
        7, 3, 4,    //H D E
        0, 4, 3,    //A E D
        0, 4, 1,    //A E B
        1, 4, 5,    //B E F
        1, 5, 6,    //B F G
        1, 2, 6,    //B C G
        2, 6, 3,    //C G D
        3, 6, 7,    //D G H
        7, 4, 6,    //H E G
        4, 5, 6,    //E F G
        8, 9, 10,   //I J K
        9, 11, 10,  //J L K
        10, 12, 8,  //K M I
        8, 12, 9,   //I M J
        9, 12, 11,  //J M L
        11, 12, 10  //L M K
    };
    tree->InitFromData(vertices, indices);
    return tree;
}