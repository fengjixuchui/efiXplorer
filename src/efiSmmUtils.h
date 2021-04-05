/*
 *        __ ___   __      _
 *       / _(_) \ / /     | |
 *   ___| |_ _ \ V / _ __ | | ___  _ __ ___ _ __
 *  / _ \  _| | > < | '_ \| |/ _ \| '__/ _ \ '__|
 * |  __/ | | |/ . \| |_) | | (_) | | |  __/ |
 *  \___|_| |_/_/ \_\ .__/|_|\___/|_|  \___|_|
 *                  | |
 *                  |_|
 *
 * efiXplorer
 * Copyright (C) 2020-2021  Binarly
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * efiSmmUtils.h
 *
 */

#include "efiUtils.h"

struct efiGuid {
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t data4[8];
};

vector<ea_t> findSmstSwDispatch(vector<ea_t> gBsList,
                                vector<segment_t *> dataSegments);
vector<ea_t> findSmstSmmBase(vector<ea_t> gBsList,
                             vector<segment_t *> dataSegments);
vector<func_t *> findSmiHandlers(ea_t address);
vector<func_t *> findSmiHandlersSmmSwDispatch(vector<segment_t *> dataSegments,
                                              vector<json> stackGuids);
vector<func_t *> findSmiHandlersSmmSwDispatchStack(vector<json> stackGuids);
vector<ea_t> findSmmGetVariableCalls(vector<segment_t *> dataSegments,
                                     vector<json> *allServices);
vector<ea_t> resolveEfiSmmCpuProtocol(vector<json> stackGuids,
                                      vector<json> dataGuids,
                                      vector<json> *allServices);
