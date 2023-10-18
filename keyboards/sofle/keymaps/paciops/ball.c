#include "ball.h"
#include <stdlib.h> // Include the standard library
#include <stdio.h> // Include the standard library
#include QMK_KEYBOARD_H

void update_ball_velocity(Ball *ball) {
    // Update the ball's velocity based on random value
    srand(timer_read());
    ball->vx = (rand() % MAX_VELOCITY) - 1; // Set a random initial velocity along the x-axis
    ball->vy = (rand() % MAX_VELOCITY) - 1; // Set a random initial velocity along the y-axis
}

// Function to initialize the ball's position and velocity
void spawn_ball(Ball *ball) {
    ball->x = OLED_WIDTH / 2; // Set the initial x-coordinate of the ball to the middle of the display
    ball->y = OLED_HEIGHT / 2; // Set the initial y-coordinate of the ball to the middle of the display
    update_ball_velocity(ball); // Update the ball's velocity
}

// Function to update the position of the ball based on its velocity
void update_ball_position(Ball *ball) {
    ball->x += ball->vx; // Update the x-coordinate of the ball based on its velocity
    ball->y += ball->vy; // Update the y-coordinate of the ball based on its velocity
    // Check for collisions with the walls and adjust the velocity accordingly
    if (ball->x - BALL_RADIUS < 0 || ball->x + BALL_RADIUS > OLED_WIDTH) {
        ball->vx = -ball->vx; // Reverse the x-axis velocity if the ball hits the left or right wall
    }
    if (ball->y - BALL_RADIUS < 0 || ball->y + BALL_RADIUS > OLED_HEIGHT) {
        ball->vy = -ball->vy; // Reverse the y-axis velocity if the ball hits the top or bottom wall
    }
}

// Function to draw the ball on the OLED display
void draw_ball(Ball *ball) {
    oled_clear();
    // Set the pixel at the ball's position and within the ball's radius to be displayed
    for (int i = -BALL_RADIUS; i <= BALL_RADIUS; i++) {
        for (int j = -BALL_RADIUS; j <= BALL_RADIUS; j++) {
            // Check if the pixel is within the bounds of the OLED display
            if (ball->x + i >= 0 && ball->x + i < OLED_WIDTH && ball->y + j >= 0 && ball->y + j < OLED_HEIGHT) {
                oled_write_pixel(ball->x + i, ball->y + j, 1); // Set the pixel at position (ball->x + i, ball->y + j) to be displayed
            }
        }
    }
    // char buffer[20]; // Buffer for holding the string

    // // Convert the x coordinate to a string and write it to the OLED display
    // sprintf(buffer, "X: %d", ball->x);
    // oled_write(buffer, false);

    // // Move to the next line on the OLED display
    // oled_write("\n", false);

    // // Convert the y coordinate to a string and write it to the OLED display
    // sprintf(buffer, "Y: %d", ball->y);
    // oled_write(buffer, false);
}
