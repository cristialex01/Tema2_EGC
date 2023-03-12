#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema2/tema_camera.h"


namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
     public:
         Tema2();
        ~Tema2();

        void Init() override;

     private:
        void FrameStart() override;
        void RenderScene(float deltaTimeSeconds, implemented::Tema_Camera *cam);
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, implemented::Tema_Camera* cam);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        implemented::Tema_Camera* tema_camera;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget;

        // TODO(student): If you need any other class variables, define them here.
        float positionX, positionZ, carSpeed, angle;

        std::vector<glm::vec3> raw_coords =
        {
            glm::vec3(0, 0, 0),
            glm::vec3(5.06f, 0, -1.33f),
            glm::vec3(9.9f, 0, -3.22f),
            glm::vec3(13.95f, 0, -5.19f),
            glm::vec3(17.63f, 0, -6.63f),
            glm::vec3(21.58f, 0, -7.62f),
            glm::vec3(25.44f, 0, -7.44f),
            glm::vec3(29.03f, 0, -6.27f),
            glm::vec3(31.28f, 0, -4.74f),
            glm::vec3(33.25f, 0, -2.14f),
            glm::vec3(34.15f, 0, 0.99f),
            glm::vec3(34.33f, 0, 4.62f),
            glm::vec3(33.25f, 0, 7.1f),
            glm::vec3(31.45f, 0, 8.63f),
            glm::vec3(28.94f, 0, 9.7f),
            glm::vec3(25.96f, 0, 10.24f),
            glm::vec3(23.82f, 0, 12.04f),
            glm::vec3(22.39f, 0, 14.37f),
            glm::vec3(22.12f, 0, 17.16f),
            glm::vec3(23.01f, 0, 20.03f),
            glm::vec3(25.44f, 0, 22.1f),
            glm::vec3(27.95f, 0, 23.08f),
            glm::vec3(31.9f, 0, 23.35f),
            glm::vec3(36.84f, 0, 23.08f),
            glm::vec3(39.9f, 0, 21.83f),
            glm::vec3(41.87f, 0, 19.22f),
            glm::vec3(43.94f, 0, 17.07f),
            glm::vec3(45.0f, 0, 15.0f),
            glm::vec3(46.16f, 0, 13.21f),
            glm::vec3(47.98f, 0, 11.59f),
            glm::vec3(50.67f, 0, 11.05f),
            glm::vec3(54.44f, 0, 12.04f),
            glm::vec3(58.12f, 0, 10.86f),
            glm::vec3(61.89f, 0, 12.22f),
            glm::vec3(66.38f, 0, 10.51f),
            glm::vec3(69.51f, 0, 12.26f),
            glm::vec3(72.32f, 0, 11.58f),
            glm::vec3(75.0f, 0, 10.0f),
            glm::vec3(78.51f, 0, 10.87f),
            glm::vec3(80.93f, 0, 12.67f),
            glm::vec3(81.29f, 0, 15.36f),
            glm::vec3(79.94f, 0, 17.25f),
            glm::vec3(78.06f, 0, 18.5f),
            glm::vec3(75.36f, 0, 19.22f),
            glm::vec3(71.14f, 0, 21.11f),
            glm::vec3(69.16f, 0, 20.51f),
            glm::vec3(67.24f, 0, 19.37f),
            glm::vec3(65.05f, 0, 18.5f),
            glm::vec3(62.86f, 0, 19.37f),
            glm::vec3(59.79f, 0, 22.0f),
            glm::vec3(59.97f, 0, 24.19f),
            glm::vec3(59.27f, 0, 26.29f),
            glm::vec3(57.4f, 0, 30.81f),
            glm::vec3(55.94f, 0, 32.07f),
            glm::vec3(53.49f, 0, 33.21f),
            glm::vec3(51.04f, 0, 32.07f),
            glm::vec3(48.76f, 0, 33.47f),
            glm::vec3(45.0f, 0, 35.0f),
            glm::vec3(40.52f, 0, 36.64f),
            glm::vec3(38.95f, 0, 38.2f),
            glm::vec3(38.25f, 0, 40.13f),
            glm::vec3(37.02f, 0, 43.38f),
            glm::vec3(36.06f, 0, 45.47f),
            glm::vec3(33.96f, 0, 46.96f),
            glm::vec3(31.42f, 0, 47.57f),
            glm::vec3(28.88f, 0, 47.22f),
            glm::vec3(27.31f, 0, 46.17f),
            glm::vec3(26.69f, 0, 43.98f),
            glm::vec3(28.44f, 0, 39.16f),
            glm::vec3(29.76f, 0, 37.41f),
            glm::vec3(29.96f, 0, 35.65f),
            glm::vec3(29.43f, 0, 33.86f),
            glm::vec3(28.04f, 0, 33.23f),
            glm::vec3(25.98f, 0, 33.05f),
            glm::vec3(23.96f, 0, 34.11f),
            glm::vec3(22.11f, 0, 35.57f),
            glm::vec3(20.0f, 0, 40.0f),
            glm::vec3(18.43f, 0, 42.38f),
            glm::vec3(16.3f, 0, 43.73f),
            glm::vec3(10.0f, 0, 45.0f),
            glm::vec3(8.02f, 0, 44.43f),
            glm::vec3(7.39f, 0, 42.7f),
            glm::vec3(7.31f, 0, 40.81f),
            glm::vec3(8.34f, 0, 35.53f),
            glm::vec3(9.36f, 0, 33.63f),
            glm::vec3(8.67f, 0, 31.66f),
            glm::vec3(8.65f, 0, 30.09f),
            glm::vec3(7.08f, 0, 28.98f),
            glm::vec3(4.79f, 0, 29.06f),
            glm::vec3(1.89f, 0, 30.05f),
            glm::vec3(0.37f, 0, 32.06f),
            glm::vec3(-1.27f, 0, 33.32f),
            glm::vec3(-4.82f, 0, 35.84f),
            glm::vec3(-6.79f, 0, 37.1f),
            glm::vec3(-8.57f, 0, 36.19f),
            glm::vec3(-9.38f, 0, 34.48f),
            glm::vec3(-7.97f, 0, 30.48f),
            glm::vec3(-8.67f, 0, 28.74f),
            glm::vec3(-13.11f, 0, 27.63f),
            glm::vec3(-14.83f, 0, 28.19f),
            glm::vec3(-16.53f, 0, 29.54f),
            glm::vec3(-18.22f, 0, 30.32f),
            glm::vec3(-20.0f, 0, 30.0f),
            glm::vec3(-21.06f, 0, 27.88f),
            glm::vec3(-20.35f, 0, 26.14f),
            glm::vec3(-18.75f, 0, 24.81f),
            glm::vec3(-18.06f, 0, 22.83f),
            glm::vec3(-18.69f, 0, 21.02f),
            glm::vec3(-18.46f, 0, 18.89f),
            glm::vec3(-16.41f, 0, 17.87f),
            glm::vec3(-13.57f, 0, 17.16f),
            glm::vec3(-8.49f, 0, 17.29f),
            glm::vec3(-6.24f, 0, 16.29f),
            glm::vec3(-5.63f, 0, 14.66f),
            glm::vec3(-5.73f, 0, 12.98f),
            glm::vec3(-6.82f, 0, 11.74f),
            glm::vec3(-10.0f, 0, 10.0f),
            glm::vec3(-12.29f, 0, 10.24f),
            glm::vec3(-15.04f, 0, 10.89f),
            glm::vec3(-20.3f, 0, 13.72f),
            glm::vec3(-23.61f, 0, 13.96f),
            glm::vec3(-26.69f, 0, 12.91f),
            glm::vec3(-28.55f, 0, 11.13f),
            glm::vec3(-28.87f, 0, 9.19f),
            glm::vec3(-27.17f, 0, 5.79f),
            glm::vec3(-26.53f, 0, 4.23f),
            glm::vec3(-26.55f, 0, 0.52f),
            glm::vec3(-25.78f, 0, -2.30f),
            glm::vec3(-24.15f, 0, -4.17f),
            glm::vec3(-20.43f, 0, -5.61f),
            glm::vec3(-18.78f, 0, -6.24f),
            glm::vec3(-17.46f, 0, -5.43f),
            glm::vec3(-13.1f, 0, -1.52f),
            glm::vec3(-11.68f, 0, -0.17f),
            glm::vec3(-9.12f, 0, 0.81f),
            glm::vec3(-6.07f, 0, 0.67f),
            glm::vec3(-3.29f, 0, 0.03f)
        };
        std::vector<glm::vec3> coords;
    };
}   // namespace m1
