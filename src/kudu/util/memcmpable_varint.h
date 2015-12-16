// Copyright 2013 Cloudera, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// This is an alternate varint format, borrowed from sqlite4, that differs from the
// varint in util/coding.h in that its serialized form can be compared with memcmp(),
// yielding the same result as comparing the original integers.
//
// The serialized form also has the property that multiple such varints can be strung
// together to form a composite key, which itself is memcmpable.
//
// See memcmpable_varint.cc for further description.

#ifndef KUDU_UTIL_MEMCMPABLE_VARINT_H
#define KUDU_UTIL_MEMCMPABLE_VARINT_H

#include "kudu/util/faststring.h"
#include "kudu/util/slice.h"

namespace kudu {

void PutMemcmpableVarint64(faststring *dst, uint64_t value);

// Standard Get... routines parse a value from the beginning of a Slice
// and advance the slice past the parsed value.
bool GetMemcmpableVarint64(Slice *input, uint64_t *value);

} // namespace kudu

#endif