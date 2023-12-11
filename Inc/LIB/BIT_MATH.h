#ifndef HEADER_FILES_BIT_MATH_H_
#define HEADER_FILES_BIT_MATH_H_

#define BIT_MASK 1UL

/**
 * @brief Set a specific bit in a register.
 *
 * @param[in,out] REG The register to modify.
 * @param[in] POS The position of the bit to set.
 */
#define SET_BIT(REG, POS)       (REG |= (1 << POS))

/**
 * @brief Clear a specific bit in a register.
 *
 * @param[in,out] REG The register to modify.
 * @param[in] POS The position of the bit to clear.
 */
#define CLR_BIT(REG, POS)       (REG &= ~(1 << POS))

/**
 * @brief Toggle a specific bit in a register.
 *
 * @param[in,out] REG The register to modify.
 * @param[in] POS The position of the bit to toggle.
 */
#define Toggle_BIT(REG, POS)    (REG ^= (1 << POS))

/**
 * @brief Read the value of a specific bit in a register.
 *
 * @param[in] REG The register to read from.
 * @param[in] POS The position of the bit to read.
 * @return The value of the specified bit.
 */
#define READ_BIT(REG, POS)      ((REG >> POS) & BIT_MASK)

/**
 * @brief Read the value of a register.
 *
 * @param[in] REG The register to read from.
 * @return The value of the register.
 */
#define READ_REG(REG)           ((REG))

/**
 * @brief Write a value to a register.
 *
 * @param[out] REG The register to write to.
 * @param[in] VAL The value to write.
 */
#define WRITE_REG(REG, VAL)     ((REG) = (VAL))

/**
 * @brief Modify a register by clearing and setting specific bits.
 *
 * @param[in,out] REG The register to modify.
 * @param[in] CLR_MSK The bit mask to clear bits.
 * @param[in] SET_MSK The bit mask to set bits.
 */
#define MODIFY_REG(REG, CLR_MSK, SET_MSK) WRITE_REG((REG), (((READ_REG(REG)) & (~(CLR_MSK))) | (SET_MSK)))
    

#endif /* HEADER_FILES_BIT_MATH_H_ */
