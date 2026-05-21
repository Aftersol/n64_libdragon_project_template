/**
 * @file save.h
 * @brief Definitions for saving data functions
 */

#ifndef __SAVE_H
#define __SAVE_H

/**
 * @brief Save data struct
 */
typedef struct {
    /**
     * @brief Foo
     */
    unsigned char foo;

    /**
     * @brief Bar
     */
    unsigned char bar;
} save_t; 

/* Definition of saving initalization functions */

/**
 * @brief Initialize the save on EEPROM
 * @return Whether the EEPROM was successfully initalized
 */
bool save_init_eeprom_save();

/**
 * @brief Initialize the save on Game Pak
 * @return Whether the save on Game Pak was successfully initalized
 */
bool save_init_gamepak_save(unsigned char port);

/**
 * @brief Initialize the save on SD card.
 * 
 * @brief If you are porting the save to across different platforms, 
 * @brief make sure to take account of the endianness of processors
 * @brief N64 uses big endian, x86 uses little endian
 * 
 * @return Whether the save on SD card was successfully initalized
 */
bool save_init_sd_save(void);

/* Definition of EEPROM saving functions */

/**
 * @brief Create a new save entry on EEPROM
 * @return Whether the creation of the save on the EEPROM is successful
 */
bool save_eeprom_create(void);

/**
 * @brief Read an existing save entry on EEPROM
 * @return Whether the read of the save from the EEPROM is successful
*/
bool save_eeprom_read(void);

/** 
 * @brief Update an existing save entry on EEPROM
 * @return Whether the update of the save on the EEPROM is successful
 */ 
bool save_eeprom_update(void);

/**
 * @brief Delete a save entry on EEPROM
 * @return Whether the deletion of the save on the EEPROM is successful
 */
bool save_eeprom_delete(void);

/* Definition of Gamepak saving functions */

/**
 * @brief Create a new save entry on a Gamepak
 * @return Whether the creation of the save on a controller is successful
 */
bool save_gamepak_create(unsigned char port);

/**
 * @brief Read an existing save entry on a Gamepak
 * @return Whether the read of the save on a controller is successful
*/
bool save_gamepak_read(unsigned char port);

/** 
 * @brief Update an existing save entry on a Gamepak
 * @return Whether the update of the save on a controller is successful
 */ 
bool save_gamepak_update(unsigned char port);

/**
 * @brief Delete a save entry on a Gamepak
 * @return Whether the deletion of the save on a controller is successful
 */
bool save_gamepak_delete(unsigned char port);

/* Definition of SD card saving functions */

/**
 * @brief Create a save entry on SD card
 * @return Whether the creation of the save on the SD card is successful
 */
bool sd_create(const char *filename);

/**
 * @brief Read a save entry on SD card
 * @return Whether the read of the save from the SD card is successful
 */
bool sd_read(const char *filename);

/**
 * @brief Update a save entry on SD card
 * @return Whether the update of the save on the SD card is successful
 */
bool sd_update(const char *filename);

/**
 * @brief Delete a save entry on SD card
 * @return Whether the deletion of the save on the SD card is successful
 */
bool sd_delete(const char *filename);

#endif