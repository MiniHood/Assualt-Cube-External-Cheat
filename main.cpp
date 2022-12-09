#include <Windows.h>
#include <iostream>

// Offsets for the player's speed and jump height in the game's memory
const int SPEED_OFFSET = 0x12345;
const int JUMP_HEIGHT_OFFSET = 0x23456;

// The base address of the game's memory in the process
const int BASE_ADDRESS = 0x34567;

// The speed and jump height values to use in the game
const float SPEED_VALUE = 10.0f;
const float JUMP_HEIGHT_VALUE = 20.0f;

int main()
{
    // Get a handle to the game's process
    HANDLE gameHandle = OpenProcess(PROCESS_ALL_ACCESS, false, 12345);

    // Check if we were able to get a handle to the game's process
    if (gameHandle == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to get handle to game process.\n";
        return 1;
    }

    // Continuously modify the player's speed and jump height in the game
    while (true)
    {
        // Calculate the address of the player's speed and jump height in the game's memory
        int speedAddress = BASE_ADDRESS + SPEED_OFFSET;
        int jumpHeightAddress = BASE_ADDRESS + JUMP_HEIGHT_OFFSET;

        // Write the new speed and jump height values to the game's memory
        WriteProcessMemory(gameHandle, (LPVOID)speedAddress, &SPEED_VALUE, sizeof(SPEED_VALUE), NULL);
        WriteProcessMemory(gameHandle, (LPVOID)jumpHeightAddress, &JUMP_HEIGHT_VALUE, sizeof(JUMP_HEIGHT_VALUE), NULL);
    }

    return 0;
}
