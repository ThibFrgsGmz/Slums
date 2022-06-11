/**
 * @file StandardTypes.hpp
 * @author Esteban Duran (@astroesteban)
 * @brief Overrides the default F Prime types in favor of Tiva-specific types
 * @version 1.0.0
 * @date 2022-02-11
 *
 */
#ifndef STANDARD_TYPES_HPP
#define STANDARD_TYPES_HPP

#include <cstdint>

#define NAME_MAX 255

typedef int TaskIdRepr;

#define FPRIME_OVERRIDE_NATIVE_TYPES

typedef int32_t NATIVE_INT_TYPE;

typedef uint32_t NATIVE_UINT_TYPE;

#endif