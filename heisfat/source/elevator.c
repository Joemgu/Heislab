#include "../inc/elevator.h"

/**
 * @brief Set the current state of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param a_current_state The state to set for the elevator.
 */
void set_current_state(Elevator *anElevator, Elevator_state_t a_current_state)
{
    anElevator->current_state = a_current_state;
}

/**
 * @brief Get the current state of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return The current state of the elevator.
 */
Elevator_state_t get_current_state(Elevator *anElevator)
{
    return anElevator->current_state;
}

/**
 * @brief Set the destination floor of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param destination_floor The destination floor to set.
 */
void set_destination_floor(Elevator *anElevator, int destination_floor)
{
    if(destination_floor < 0 || destination_floor > N_FLOORS)
    {
        //later implement interrupt
        //prints "Floor out of bound"
        printf("Floor out of bound\n");
    }
    anElevator->destination_floor = destination_floor;
    return;
};

/**
 * @brief Get the destination floor of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return The destination floor of the elevator.
 */
int get_destination_floor(Elevator *anElevator)
{
    return anElevator->destination_floor;
}

/**
 * @brief Set the current floor of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param a_current_floor The current floor to set for the elevator.
 */
void set_current_floor(Elevator *anElevator, int a_current_floor)
{
    anElevator->current_floor = a_current_floor;
}

/**
 * @brief Get the current floor of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return The current floor of the elevator.
 */
int get_current_floor(Elevator *anElevator)
{
    return anElevator->current_floor;
}

/**
 * @brief Set whether the elevator has a destination.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param has_a_destination True if the elevator has a destination, false otherwise.
 */
void set_has_destination(Elevator *anElevator, bool has_a_destination)
{
    anElevator->has_destination = has_a_destination;
}

/**
 * @brief Get whether the elevator has a destination.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return True if the elevator has a destination, false otherwise.
 */
bool get_has_destination(Elevator *anElevator)
{
    return anElevator->has_destination;
}

/**
 * @brief Set the moving direction of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @param moving_up True if the elevator is moving up, false if moving down.
 */
void set_moving_up(Elevator *anElevator, bool moving_up)
{
    anElevator->moving_up = moving_up;
}

/**
 * @brief Get the moving direction of the elevator.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return True if the elevator is moving up, false if moving down.
 */
bool get_moving_up(Elevator *anElevator)
{
    return anElevator->moving_up;
}

/**
 * @brief Switch the moving direction of the elevator (up or down).
 * 
 * @param anElevator Pointer to the Elevator object.
 */
void switch_moving_direction(Elevator *anElevator)
{
    if(anElevator->moving_up)
    {
        anElevator->moving_up = false;
    } 
    else 
    {
        anElevator->moving_up = true;
    }
    return;
}

/**
 * @brief Set the start time of the elevator's movement.
 * 
 * @param anElevator Pointer to the Elevator object.
 */
void set_start_time(Elevator *anElevator)
{
    anElevator->start_time = time(NULL);
}

/**
 * @brief Get the time difference since the elevator started moving.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return The time difference in seconds since the elevator started moving.
 */
int get_time_difference(Elevator *anElevator)
{
    return (int)time(NULL) - anElevator->start_time;
}

/**
 * @brief Check if the elevator is currently moving.
 * 
 * @param anElevator Pointer to the Elevator object.
 * @return True if the elevator is moving, false if it is not.
 */
bool get_is_moving(Elevator *anElevator) 
{
    if ((anElevator->current_state) == MOVING)
    {
        return true;
    } 
    else
    {
        return false;
    } 
}
