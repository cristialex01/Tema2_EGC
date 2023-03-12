#include "lab_m1/Tema2/tema2.h"
#include "lab_m1/Tema2/obj3D.h"

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{
    renderCameraTarget = false;

    tema_camera = new implemented::Tema_Camera();
    tema_camera->Set(glm::vec3(-1, 1, 0), glm::vec3(1, 0, 0), glm::vec3(0, 1, 0));
    Mesh* track = obj3D::CreateTrack("track", glm::vec3(0, 0, 0));
    meshes["track"] = track;
    Mesh* grass = obj3D::CreateGrass("grass", glm::vec3(0, 0, 0));
    meshes["grass"] = grass;
    Mesh* car = obj3D::CreateSimpleCar("car", glm::vec3(0, 0, 0));
    meshes["car"] = car;
    Mesh* tree = obj3D::CreateTree("tree", glm::vec3(0, 0, 0));
    meshes["tree"] = tree;

    //Calculate coords for tree
    {
        glm::vec3 dist, p;
        for (int i = 0; i < raw_coords.size() - 2; i += 2)
        {
            dist = raw_coords[i + 1] - raw_coords[i];
            p = normalize(glm::cross(dist, glm::vec3_up));
            if (rand() % 2)
                coords.push_back(raw_coords[i] - 2.f * p);
            else
                coords.push_back(raw_coords[i] + 2.f * p);
        }
    }

    positionX = 0;
    positionZ = 0;
    carSpeed = 0;
    angle = M_PI_2;
}


void Tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.172f, 0.721f, 0.749f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::RenderScene(float deltaTimeSeconds, implemented::Tema_Camera *cam)
{ //Render track
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        RenderMesh(meshes["track"], shaders["VertexColor"], modelMatrix, cam);
    }

    //Render grass
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(-40, -0.01f, -20));
        RenderMesh(meshes["grass"], shaders["VertexColor"], modelMatrix, cam);
    }

    //Render car
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(positionX, 0.01f, positionZ));
        modelMatrix = glm::rotate(modelMatrix, angle, glm::vec3_up);
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2f, 0.2f, 0.2f));
        RenderMesh(meshes["car"], shaders["VertexColor"], modelMatrix, cam);
    }

    //Render trees
    for (int i = 0; i < coords.size() - 2; i++)
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, coords[i]);
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f, 0.25f, 0.25f));
        RenderMesh(meshes["tree"], shaders["VertexColor"], modelMatrix, cam);
    }
}

void Tema2::Update(float deltaTimeSeconds)
{
    //Camera position
    glm::vec3 direction = glm::normalize(glm::vec3(glm::rotate(glm::mat4(1), angle, glm::vec3_up) * glm::vec4(glm::vec3(0, 0, 1), 1)));
    //Update car position
    positionX += deltaTimeSeconds * carSpeed * direction.x;
    positionZ += deltaTimeSeconds * carSpeed * direction.z;

    //Move the camera with right click
    if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
        tema_camera->Set(glm::vec3(positionX, 0, positionZ) - direction * 1.5f + glm::vec3(0, 1, 0), glm::vec3(positionX, 0.6f, positionZ), glm::vec3(0, 1, 0));

    projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
    RenderScene(deltaTimeSeconds, tema_camera);

    glm::ivec2 resolution = window->GetResolution();
    glClear(GL_DEPTH_BUFFER_BIT);
    glViewport(50, 50, resolution.x/5.0f, resolution.y/5.0f);

    implemented::Tema_Camera cameraDeSus;
    cameraDeSus.Set(glm::vec3(positionX, 3, positionZ), glm::vec3(positionX, 1, positionZ), glm::vec3_right);
    projectionMatrix = glm::ortho(-6.f, 6.f, -6.f, 6.f, 0.01f, 20.f);
    RenderScene(deltaTimeSeconds, &cameraDeSus);
}


void Tema2::FrameEnd()
{
}


void Tema2::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix, implemented::Tema_Camera *cam)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(cam->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    //Move forward
    if (window->KeyHold(GLFW_KEY_W))
        if (carSpeed < 0)
            carSpeed += 0.05;
        else if(carSpeed <= 4.5)
            carSpeed += 0.02;

    //Move backward
    if (window->KeyHold(GLFW_KEY_S))
        if (carSpeed > 0)
            carSpeed -= 0.05;
        else if (carSpeed >= -1.5)
            carSpeed -= 0.02;
    
    //Decelerate to 0
    if (!window->KeyHold(GLFW_KEY_W) && !window->KeyHold(GLFW_KEY_S) && carSpeed > 0)
    {
        carSpeed -= 0.005f;
        if (carSpeed < 0)
            carSpeed = 0;
    }

    //Accelerate to 0
    if (!window->KeyHold(GLFW_KEY_W) && !window->KeyHold(GLFW_KEY_S) && carSpeed < 0)
    {
        carSpeed += 0.005f;
        if (carSpeed > 0)
            carSpeed = 0;
    }
    
    //Turning
    if (carSpeed > 0.25)
    {
        //Move forward and turn left
        if (window->KeyHold(GLFW_KEY_A))
            angle += deltaTime;

        //Move forward and turn right
        if (window->KeyHold(GLFW_KEY_D))
            angle -= deltaTime;
        
    }
    
    if (carSpeed < -0.25)
    {
        //Move backward and turn left
        if (window->KeyHold(GLFW_KEY_A))
            angle -= deltaTime;

        //Move backward and turn right
        if (window->KeyHold(GLFW_KEY_D))
            angle += deltaTime;
    }
}


void Tema2::OnKeyPress(int key, int mods)
{
}


void Tema2::OnKeyRelease(int key, int mods)
{
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event

    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float sensivityOX = 0.001f;
        float sensivityOY = 0.001f;

        tema_camera->RotateThirdPerson_OX(sensivityOX * -deltaY);
        tema_camera->RotateThirdPerson_OY(sensivityOY * -deltaX);
    }
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
