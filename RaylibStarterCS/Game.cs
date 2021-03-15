using System;
using System.Diagnostics;
using System.Numerics;
using Raylib_cs;
using static Raylib_cs.Raylib;

namespace RaylibStarterCS
{
    class Game
    {
        Stopwatch stopwatch = new Stopwatch();

        private long currentTime = 0;
        private long lastTime = 0;
        private float timer = 0;
        private int fps = 1;
        private int frames;

        private float deltaTime = 0.005f;

        Image logo;
        Texture2D logoTexture;

        Image ship;
        Texture2D shipTexture;

        float m_timer = 0;

        Camera2D camera;

        public Game()
        {
        }

        public void Init()
        {
            stopwatch.Start();
            lastTime = stopwatch.ElapsedMilliseconds;

            if (Stopwatch.IsHighResolution)
            {
                Console.WriteLine("Stopwatch high-resolution frequency: {0} ticks per second", Stopwatch.Frequency);
            }

            logo = LoadImage("../Images/aie-logo-dark.png");
            logoTexture = LoadTextureFromImage(logo);

            ship = LoadImage("../Images/ship.png");
            shipTexture = LoadTextureFromImage(ship);

            SetTargetFPS(60);       // Set our game to run at 60 frames-per-second

            camera.target = new Vector2(0, 0);
            camera.offset = Vector2.Zero;
            camera.rotation = 0;
            camera.zoom = 1.0f;
        }

        public void Shutdown()
        {
        }

        public void Update()
        {
            lastTime = currentTime;
            currentTime = stopwatch.ElapsedMilliseconds;
            deltaTime = (currentTime - lastTime) / 1000.0f;
            timer += deltaTime;
            if (timer >= 1)
            {
                fps = frames;
                frames = 0;
                timer -= 1;
            }
            frames++;

            // insert game logic here            

            m_timer += deltaTime;

            // use arrow keys to move camera
            if (IsKeyDown(KeyboardKey.KEY_UP))
                camera.target.Y += 500.0f * deltaTime;

            if (IsKeyDown(KeyboardKey.KEY_DOWN))
                camera.target.Y -= 500.0f * deltaTime;

            if (IsKeyDown(KeyboardKey.KEY_LEFT))
                camera.target.X -= 500.0f * deltaTime;

            if (IsKeyDown(KeyboardKey.KEY_RIGHT))
                camera.target.X += 500.0f * deltaTime;


            // Camera zoom controls
            camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

            if (camera.zoom > 3.0f) camera.zoom = 3.0f;
            else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

            // Camera reset (zoom and rotation)
            if (IsKeyPressed(KeyboardKey.KEY_R))
            {
                camera.zoom = 1.0f;
                camera.rotation = 0.0f;
            }
        }

        public void Draw()
        {
            BeginDrawing();
                BeginMode2D(camera);

                    ClearBackground(Color.WHITE);

			DrawTexture(logoTexture,
				GetScreenWidth() - logoTexture.width, 0, Color.WHITE);

            // demonstrate spinning sprite
            DrawTextureEx(shipTexture, new Vector2(150, 300), m_timer*30, 1, Color.WHITE);

            // draw a thin line
            DrawLine(300, 300, 600, 400, Color.BLACK);

            // draw a moving purple circle
            DrawCircle((int)(Math.Sin(m_timer) * 100) + 300, 150, 50, Color.PURPLE);
            
            // draw a rotating red box
            DrawRectanglePro(new Rectangle(100, 200, 60, 20), new Vector2(30, 10), m_timer*30, Color.RED);

            EndMode2D();

                DrawText(fps.ToString(), 10, 10, 14, Color.RED);

            EndDrawing();
        }

    }
}
