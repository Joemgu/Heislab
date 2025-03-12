#pragma once 
#include <time.h>
#include <stdbool.h>
#include "../source/driver/elevio.h"
#include <stdio.h>

// Enum for the different states of the elevator
/**
 * @brief Enum for the different states of the elevator.
 */
typedef enum {
    IDLE,           /**< Elevator is idle, not moving */
    MOVING,         /**< Elevator is currently moving */
    AT_DESTINATION, /**< Elevator has reached the destination floor */
    EMERGENCY       /**< Elevator is in an emergency state */
} Elevator_state_t; 

// Test, maybe use later
// typedef void(*state_handler_ptr_fun)(Elevator* anElevator);

/**
 * @brief Structure to represent the elevator's state and properties.
 */
typedef struct {
    Elevator_state_t current_state; /**< The current state of the elevator */
    int current_floor;             /**< The current floor of the elevator */
    int destination_floor;         /**< The next order to be executed */
    bool has_destination;          /**< Boolean to indicate if the elevator has a destination floor */
    bool moving_up;                /**< Boolean indicating the direction of movement (true = up, false = down) */
    time_t start_time;             /**< Time the elevator started its movement */
} Elevator;

/**
 * @brief Set the current state of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param a_current_state The state to set for the elevator.
 */
void set_current_state(Elevator *anElevator, Elevator_state_t a_current_state);

/**
 * @brief Get the current state of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return The current state of the elevator.
 */
Elevator_state_t get_current_state(Elevator *anElevator);

/**
 * @brief Set the destination floor of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param destination_floor The destination floor to set (must be between 0 and 3).
 */
void set_destination_floor(Elevator *anElevator, int destination_floor);

/**
 * @brief Get the destination floor of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return The destination floor of the elevator.
 */
int get_destination_floor(Elevator *anElevator);

/**
 * @brief Set the current floor of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param a_current_floor The current floor to set for the elevator.
 */
void set_current_floor(Elevator *anElevator, int a_current_floor);

/**
 * @brief Get the current floor of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return The current floor of the elevator.
 */
int get_current_floor(Elevator *anElevator);

/**
 * @brief Set whether the elevator has a destination.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param has_a_destination True if the elevator has a destination floor, false otherwise.
 */
void set_has_destination(Elevator *anElevator, bool has_a_destination);

/**
 * @brief Get whether the elevator has a destination.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return True if the elevator has a destination floor, false otherwise.
 */
bool get_has_destination(Elevator *anElevator);

/**
 * @brief Set the start time of the elevator's movement.
 * 
 * @param anElevator Pointer to the Elevator object.
 */
void set_start_time(Elevator *anElevator);

/**
 * @brief Get the time difference in seconds since the elevator started moving.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return The time difference in seconds since the elevator started moving.
 */
int get_time_difference(Elevator *anElevator);

/**
 * @brief Set the direction of movement of the elevator (up or down).
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param moving_up True if the elevator is moving up, false if moving down.
 */
void set_moving_up(Elevator *anElevator, bool moving_up);

/**
 * @brief Get the direction of movement of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return True if the elevator is moving up, false if moving down.
 */
bool get_moving_up(Elevator *anElevator);

/**
 * @brief Switch the direction of movement of the elevator (up to down or down to up).
 * 
 * @param anElevator Pointer to the Elevator object.
 */
void switch_moving_direction(Elevator *anElevator);

/**
 * @brief Check if the elevator is currently moving.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return True if the elevator is moving, false if it is idle or at the destination.
 */
bool get_is_moving(Elevator *anElevator);
