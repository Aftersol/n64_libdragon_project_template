/**
 * @file save.c
 * @author You
 * @brief Implementation for saving data functions
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <libdragon.h>

/**
 * @brief Check if port number of a controller is vaild
 */
#define JOYPAK_PORT_VALID(port) (port < 0 || port > 3)

/**
 * @brief Whether the EEPROM is present in cartridge
 */
bool __eeprom_present = false;

/**
 * @brief Array of whether the Game Pak is 
 * @brief present in each of the four controller
 */
bool __gamepak_present[4] = {
    false,
    false,
    false,
    false
};

/**
 * @brief Whether the SD is present in a controller
 */
bool __sd_card_present = false;

/* Implementation of saving initalization functions */

/**
 * @brief Initialize the save on EEPROM
 * @return Whether the EEPROM was successfully initalized
 */
bool save_init_eeprom_save(void) {
    __eeprom_present = eeprom_present() != EEPROM_NONE;
    return __eeprom_present;
}

/**
 * @brief Initialize the save on Game Pak
 * @return Whether the save on Game Pak was successfully initalized
 */
bool save_init_gamepak_save(void) {
    int port;
    for (port = 0; port < 4; port++) {
        /* TODO: initialize gamepak on controller */
    }
    return false;
}

/**
 * @brief Initialize the save on SD card.
 * 
 * @brief If you are porting the save to across different platforms, 
 * @brief make sure to take account of the endianness of processors
 * @brief N64 uses big endian, x86 uses little endian
 * 
 * @return Whether the save on SD card was successfully initalized
 */
bool save_init_sd_save(void) {
    if (!__sd_card_present) {
        __sd_card_present = debug_init_sdfs("sd:/", -1);
        return __sd_card_present;
    }

    return true;

}

/**
 * @brief Save buffer
 */
unsigned char save_buffer[512];

/* Implementation of EEPROM saving functions */

/**
 * @brief Create a new save entry on EEPROM
 * @return Whether the creation of the save on the EEPROM is successful
 */
bool save_eeprom_create(void) {
    if (!__eeprom_present) {
        return false;
    }

    /* TODO: Implement create logic*/

    return true;
}

/**
 * @brief Read an existing save entry on EEPROM
 * @return Whether the read of the save from the EEPROM is successful
*/
bool save_eeprom_read(void) {
    if (!__eeprom_present) {
        return false;
    }

    /* TODO: Implement read logic */

    return true;
}

/** 
 * @brief Update an existing save entry on EEPROM
 * @return Whether the update of the save on the EEPROM is successful
 */ 
bool save_eeprom_update(void) {
    if (!__eeprom_present) {
        return false;
    }

    /* TODO: Implement update logic */

    return true;
}

/**
 * @brief Delete a save entry on EEPROM
 * @return Whether the deletion of the save on the EEPROM is successful
 */
bool save_eeprom_delete(void) {
    /* TODO: Implement delete logic */

    return true;
}

/* Implementation of Gamepak saving functions */

/**
 * @brief Create a new save entry on a Gamepak
 * @return Whether the creation of the save on a controller is successful
 */
bool save_gamepak_create(unsigned char port) {
    if (JOYPAK_PORT_VALID(port))
    {
        return false; 
    }

    if (!__eeprom_present) {
        return false;
    }

    /* TODO: Implement create logic */
    
    return true;
}

/**
 * @brief Read an existing save entry on a Gamepak
 * @return Whether the read of the save on a controller is successful
*/
bool save_gamepak_read(unsigned char port) {
    if (JOYPAK_PORT_VALID(port))
    {
        return false; 
    }

    if (!__eeprom_present) {
        return false;
    }

    /* TODO: Implement read logic */

    return true;
}

/** 
 * @brief Update an existing save entry on a Gamepak
 * @return Whether the update of the save on a controller is successful
 */ 
bool save_gamepak_update(unsigned char port) {
    if (JOYPAK_PORT_VALID(port))
    {
        return false; 
    }

    if (!__eeprom_present) {
        return false;
    }

    /* TODO: Implement update logic */

    return true;
}

/**
 * @brief Delete a save entry on a Gamepak
 * @return Whether the deletion of the save on a controller is successful
 */
bool save_gamepak_delete(unsigned char port) {
    if (JOYPAK_PORT_VALID(port))
    {
        return true; 
    }

    /* TODO: Implement delete logic */

    return true;
}

/* Implementation of SD card saving functions */

/**
 * @brief Create a save entry on SD card
 * @return Whether the creation of the save on the SD card is successful
 */
bool save_sd_create(const char *filename) {
    FILE *fp;

    if (!__sd_card_present) return false;
    if (!filename) return false;
    
    fp = fopen(filename, "wb");
    if (fp) {
        /* TODO: Implement SD card creation logic */

        fclose(fp);
        return true;
    }

    return false;
}

/**
 * @brief Read a save entry on SD card
 * @return Whether the read of the save from the SD card is successful
 */
bool save_sd_read(const char *filename) {
    FILE *fp;

    if (!__sd_card_present) return false;
    if (!filename) return false;

    fp = fopen(filename, "rb");
    if (fp) {
        /* TODO: Implement SD card read logic */

        fclose(fp);
        return true;
    }

    return false;
}

/**
 * @brief Update a save entry on SD card
 * @return Whether the update of the save on the SD card is successful
 */
bool save_sd_update(const char *filename) {
    FILE *fp;

    if (!__sd_card_present) return false;
    if (!filename) return false;

    fp = fopen(filename, "wb");

    if (fp) {
        /* TODO: Implement SD card update logic */

        fclose(fp);
        return true;
    }

    return false;
}

/**
 * @brief Delete a save entry on SD card
 * @return Whether the deletion of the save on the SD card is successful
 */
bool save_sd_delete(const char *filename) {
    FILE *fp;

    if (!__sd_card_present) return true;
    if (!filename) return true;

    fp = fopen(filename, "wb");
    if (!fp) {
        return true;
    }

    fclose(fp);

    remove(filename);

    return true;
}
