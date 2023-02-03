#include "raylib.h"

int main(){
    // Window attribute
    float Width{1080};
    float Height{720};
    float FPS{144};
    InitWindow(Width,Height,"Axe");

    // Initialize Circle attribute
    float CircleX{350};
    float CircleY{540};
    float Radius{70};
    float LCircle{CircleX-Radius};
    float RCircle{CircleX+Radius};
    float UCircle{CircleY-Radius};
    float BCircle{CircleY+Radius};

    // Initialize Axe attribute
    float AxeX{500};
    float AXeY{550};
    float AxeLength{100};
    float LAxe{AxeX};
    float RAxe{LAxe+AxeLength};
    float UAxe{AXeY};
    float BAxe{UAxe+AxeLength};

    // Direction
    float AxeDirection{1};
    float CircleDirection{1};

    // Collision test
    bool Collision = (LAxe <= RCircle)&&
                        (RAxe >= LCircle)&&
                        (UAxe <= BCircle)&&
                        (BAxe >= UCircle);

    SetTargetFPS(FPS);

    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(GRAY);
        // Main Game logic
        if (Collision){
            DrawText("Game over",Width/2,Height/2,20,RED);
        }
        else{
            // update the collision test
            LCircle=CircleX-Radius;
            RCircle=CircleX+Radius;
            UCircle=CircleY-Radius;
            BCircle=CircleY+Radius;
            //-----
            LAxe=AxeX;
            RAxe=LAxe+AxeLength;
            UAxe=AXeY;
            BAxe=UAxe+AxeLength;
            //-----
            Collision = (LAxe <= RCircle)&&
                        (RAxe >= LCircle)&&
                        (UAxe <= BCircle)&&
                        (BAxe >= UCircle);

            DrawCircle(CircleX,CircleY,Radius,BLUE);
            DrawRectangle(AxeX,AXeY,AxeLength,AxeLength,YELLOW);

            // input
            AXeY += AxeDirection;
            if(AXeY > Height || AXeY < 0){
                AxeDirection = -AxeDirection;
            }

            if(IsKeyDown(KEY_A) && CircleX > 0){
                CircleX -= CircleDirection;
            }
            if(IsKeyDown(KEY_D) && CircleX < Width){
                CircleX += CircleDirection;
            }
            if(IsKeyDown(KEY_W) && CircleY > 0){
                CircleY -= CircleDirection;
            }
            if(IsKeyDown(KEY_S) && CircleY < Height){
                CircleY += CircleDirection;
            }
        }


        EndDrawing();
    }
    
}