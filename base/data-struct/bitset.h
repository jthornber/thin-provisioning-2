#ifndef BASE_DATA_STRUCT_BITSET_H
#define BASE_DATA_STRUCT_BITSET_H

#include <limits.h>
#include <stdint.h>
#include <string.h>

//----------------------------------------------------------------

typedef uint32_t *dm_bitset_t;

dm_bitset_t dm_bitset_create(unsigned num_bits);
void dm_bitset_destroy(dm_bitset_t bs);

int dm_bitset_equal(dm_bitset_t in1, dm_bitset_t in2);

void dm_bit_and(dm_bitset_t out, dm_bitset_t in1, dm_bitset_t in2);
void dm_bit_union(dm_bitset_t out, dm_bitset_t in1, dm_bitset_t in2);
int dm_bit_get_first(dm_bitset_t bs);
int dm_bit_get_next(dm_bitset_t bs, int last_bit);
int dm_bit_get_last(dm_bitset_t bs);
int dm_bit_get_prev(dm_bitset_t bs, int last_bit);

#define DM_BITS_PER_INT (sizeof(int) * CHAR_BIT)

#define dm_bit(bs, i) \
   ((bs)[((i) / DM_BITS_PER_INT) + 1] & (0x1 << ((i) & (DM_BITS_PER_INT - 1))))

#define dm_bit_set(bs, i) \
   ((bs)[((i) / DM_BITS_PER_INT) + 1] |= (0x1 << ((i) & (DM_BITS_PER_INT - 1))))

#define dm_bit_clear(bs, i) \
   ((bs)[((i) / DM_BITS_PER_INT) + 1] &= ~(0x1 << ((i) & (DM_BITS_PER_INT - 1))))

#define dm_bit_set_all(bs) \
   memset((bs) + 1, -1, ((*(bs) / DM_BITS_PER_INT) + 1) * sizeof(int))

#define dm_bit_clear_all(bs) \
   memset((bs) + 1, 0, ((*(bs) / DM_BITS_PER_INT) + 1) * sizeof(int))

#define dm_bit_copy(bs1, bs2) \
   memcpy((bs1) + 1, (bs2) + 1, ((*(bs2) / DM_BITS_PER_INT) + 1) * sizeof(int))

//----------------------------------------------------------------

#endif
