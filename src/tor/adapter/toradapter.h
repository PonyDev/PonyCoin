/* Copyright (c) 2014, Razor Developers */
/* See LICENSE for licensing information */

/**
 * \file toradapter.h
 * \brief Headers for toradapter.cpp
 **/

#ifndef TOR_RAZOR_H
#define TOR_RAZOR_H

// from netbase.h
extern unsigned short onion_port;
extern unsigned short p2p_port;

#ifdef __cplusplus
extern "C" {
#endif

    char const* ponycoin_tor_data_directory(
    );

    char const* ponycoin_service_directory(
    );

    int check_interrupted(
    );

    void set_initialized(
    );

    void wait_initialized(
    );

#ifdef __cplusplus
}
#endif

#endif

