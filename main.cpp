#include "raylib.h"

int main()
{
    int width{800};
    int height{450};
    InitWindow(width, height, "Evan");

    int circle_x{200};
    int circle_y{200};
    float circle_radius{20.0};

    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    int speed{10};
    int direction{10};

    int axe_x{400};
    int axe_y{0};
    int axe_height{50};
    int axe_width{50};

    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_width};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_height};

    bool collision_with_axe{
        (b_axe_y >= u_circle_y) &&
        (u_axe_y <= b_circle_y) &&
        (l_axe_x <= r_circle_x) &&
        (r_axe_x >= l_circle_x)};

    int target_fps{60};

    SetTargetFPS(target_fps);

    while (true)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_width, axe_height, RED);

        if (collision_with_axe)
        {
            DrawText("GameOver!", 250, 100, 60, RED);
        }
        else
        {
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_width;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_height;

            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (l_axe_x <= r_circle_x) &&
                (r_axe_x >= l_circle_x);

            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += speed;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= speed;
            }
            if (IsKeyDown(KEY_S) && circle_y < height)
            {
                circle_y += speed;
            }
            if (IsKeyDown(KEY_W) && circle_y > 0)
            {
                circle_y -= speed;
            }
        }

        EndDrawing();
    }
}