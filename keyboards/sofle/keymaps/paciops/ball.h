#define OLED_WIDTH 128  // Define the width of the OLED display
#define OLED_HEIGHT 32  // Define the height of the OLED display
#define BALL_RADIUS 2   // Define the radius of the ball
#define MAX_VELOCITY 3
// Define the structure for the ball
typedef struct {
    int x;  // X-coordinate of the ball
    int y;  // Y-coordinate of the ball
    int vx; // Velocity along the x-axis
    int vy; // Velocity along the y-axis
} Ball;

// Function declarations for the ball operations
void update_ball_velocity(Ball *ball);
void spawn_ball(Ball *ball);
void update_ball_position(Ball *ball, unsigned  char speed);
void draw_ball(Ball *ball);
