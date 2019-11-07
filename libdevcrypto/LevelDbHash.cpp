/*
    Modifications Copyright (C) 2018 SKALE Labs

    This file is part of cpp-ethereum.

    cpp-ethereum is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cpp-ethereum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 * @file LevelDbHash.cpp
 */

#include "LevelDbHash.h"

namespace dev {

  dev::h256 LevelDbHash256(dev::db::LevelDB* level_db) noexcept {
    secp256k1_sha256_t ctx;
    secp256k1_sha256_initialize(&ctx);
    dev::db::LevelDB::Iterator* it = db->NewIterator(dev::db::LevelDB::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next()) {
      std::string key_ = it->key.ToString();
      std::string value_ = it->value.ToString();
      std::string key_value = key_ + value_;
      bytesConstRef str_key_value(key_value.begin(), key_value.length());
      secp256k1_sha256_write(&ctx, str_key_value.data(), str_key_value.size());
    }
    h256 hash;
    secp256k1_sha256_finalize(&ctx, hash.data());
    return hash;
  }

}