// SID-output tables (Keep them static because they're included locally inside the wave-generator function.)

static const unsigned short Resonances8580[] = {
    // generated by curvegen.c
    //  0     1      2      3      4      5      6      7      8      9      A      B      C      D      E      F
    0x16A0, 0x14BF, 0x1306, 0x1172, 0x1000, 0x0EAC, 0x0D74, 0x0C56, 0x0B50,
    0x0A5F, 0x0983, 0x08B9, 0x0800, 0x0756, 0x06BA, 0x062B
    // 0xFF,  0xFE,  0xFC,  0xF8,  0xF0,  0xE8,  0xD5,  0xC5,  0xB3,  0xA4,  0x97,  0x8A,  0x80,  0x77,  0x6E,  0x66 <-
    // calculated then refined manually to sound best
};

static const unsigned short Resonances6581[] = {
    // generated by curvegen.c
    //  0     1      2      3      4      5      6      7      8      9      A      B      C      D      E      F
    0x168F, 0x168F, 0x168F, 0x168F, 0x168F, 0x168F, 0x1555, 0x1249, 0x1000,
    0x0E38, 0x0CCC, 0x0BA2, 0x0AAA, 0x09D8, 0x0924, 0x0888
    // 0xFF,  0xFE,  0xFD,  0xFC,  0xFB,  0xF9,  0xF6,  0xF2,  0xEC,  0xE4,  0xCD,  0xBA,  0xAB,  0x9E,  0x92,  0x86 <-
    // calculated then refined manually to sound best
};

static const unsigned short CutoffMul8580_44100Hz[] = { // generated by curvegen.c
    0x006, 0x00A, 0x00D, 0x011, 0x014, 0x018, 0x01B, 0x01F, 0x022, 0x026, 0x029, 0x02D, 0x030, 0x034, 0x037, 0x03B,
    0x03E, 0x041, 0x045, 0x048, 0x04C, 0x04F, 0x053, 0x056, 0x059, 0x05D, 0x060, 0x064, 0x067, 0x06B, 0x06E, 0x071,
    0x075, 0x078, 0x07C, 0x07F, 0x082, 0x086, 0x089, 0x08D, 0x090, 0x093, 0x097, 0x09A, 0x09D, 0x0A1, 0x0A4, 0x0A7,
    0x0AB, 0x0AE, 0x0B2, 0x0B5, 0x0B8, 0x0BC, 0x0BF, 0x0C2, 0x0C6, 0x0C9, 0x0CC, 0x0D0, 0x0D3, 0x0D6, 0x0D9, 0x0DD,
    0x0E0, 0x0E3, 0x0E7, 0x0EA, 0x0ED, 0x0F1, 0x0F4, 0x0F7, 0x0FA, 0x0FE, 0x101, 0x104, 0x108, 0x10B, 0x10E, 0x111,
    0x115, 0x118, 0x11B, 0x11E, 0x122, 0x125, 0x128, 0x12B, 0x12F, 0x132, 0x135, 0x138, 0x13C, 0x13F, 0x142, 0x145,
    0x149, 0x14C, 0x14F, 0x152, 0x155, 0x159, 0x15C, 0x15F, 0x162, 0x165, 0x169, 0x16C, 0x16F, 0x172, 0x175, 0x178,
    0x17C, 0x17F, 0x182, 0x185, 0x188, 0x18B, 0x18F, 0x192, 0x195, 0x198, 0x19B, 0x19E, 0x1A2, 0x1A5, 0x1A8, 0x1AB,
    0x1AE, 0x1B1, 0x1B4, 0x1B7, 0x1BB, 0x1BE, 0x1C1, 0x1C4, 0x1C7, 0x1CA, 0x1CD, 0x1D0, 0x1D3, 0x1D7, 0x1DA, 0x1DD,
    0x1E0, 0x1E3, 0x1E6, 0x1E9, 0x1EC, 0x1EF, 0x1F2, 0x1F5, 0x1F9, 0x1FC, 0x1FF, 0x202, 0x205, 0x208, 0x20B, 0x20E,
    0x211, 0x214, 0x217, 0x21A, 0x21D, 0x220, 0x223, 0x226, 0x229, 0x22C, 0x22F, 0x232, 0x235, 0x238, 0x23B, 0x23E,
    0x241, 0x244, 0x247, 0x24A, 0x24D, 0x250, 0x253, 0x256, 0x259, 0x25C, 0x25F, 0x262, 0x265, 0x268, 0x26B, 0x26E,
    0x271, 0x274, 0x277, 0x27A, 0x27D, 0x280, 0x283, 0x286, 0x289, 0x28C, 0x28F, 0x292, 0x295, 0x297, 0x29A, 0x29D,
    0x2A0, 0x2A3, 0x2A6, 0x2A9, 0x2AC, 0x2AF, 0x2B2, 0x2B5, 0x2B8, 0x2BB, 0x2BD, 0x2C0, 0x2C3, 0x2C6, 0x2C9, 0x2CC,
    0x2CF, 0x2D2, 0x2D5, 0x2D7, 0x2DA, 0x2DD, 0x2E0, 0x2E3, 0x2E6, 0x2E9, 0x2EB, 0x2EE, 0x2F1, 0x2F4, 0x2F7, 0x2FA,
    0x2FD, 0x2FF, 0x302, 0x305, 0x308, 0x30B, 0x30E, 0x310, 0x313, 0x316, 0x319, 0x31C, 0x31F, 0x321, 0x324, 0x327,
    0x32A, 0x32D, 0x32F, 0x332, 0x335, 0x338, 0x33B, 0x33D, 0x340, 0x343, 0x346, 0x349, 0x34B, 0x34E, 0x351, 0x354,
    0x356, 0x359, 0x35C, 0x35F, 0x362, 0x364, 0x367, 0x36A, 0x36D, 0x36F, 0x372, 0x375, 0x378, 0x37A, 0x37D, 0x380,
    0x382, 0x385, 0x388, 0x38B, 0x38D, 0x390, 0x393, 0x396, 0x398, 0x39B, 0x39E, 0x3A0, 0x3A3, 0x3A6, 0x3A8, 0x3AB,
    0x3AE, 0x3B1, 0x3B3, 0x3B6, 0x3B9, 0x3BB, 0x3BE, 0x3C1, 0x3C3, 0x3C6, 0x3C9, 0x3CB, 0x3CE, 0x3D1, 0x3D3, 0x3D6,
    0x3D9, 0x3DB, 0x3DE, 0x3E1, 0x3E3, 0x3E6, 0x3E9, 0x3EB, 0x3EE, 0x3F1, 0x3F3, 0x3F6, 0x3F8, 0x3FB, 0x3FE, 0x400,
    0x403, 0x406, 0x408, 0x40B, 0x40D, 0x410, 0x413, 0x415, 0x418, 0x41A, 0x41D, 0x420, 0x422, 0x425, 0x427, 0x42A,
    0x42D, 0x42F, 0x432, 0x434, 0x437, 0x439, 0x43C, 0x43F, 0x441, 0x444, 0x446, 0x449, 0x44B, 0x44E, 0x451, 0x453,
    0x456, 0x458, 0x45B, 0x45D, 0x460, 0x462, 0x465, 0x467, 0x46A, 0x46D, 0x46F, 0x472, 0x474, 0x477, 0x479, 0x47C,
    0x47E, 0x481, 0x483, 0x486, 0x488, 0x48B, 0x48D, 0x490, 0x492, 0x495, 0x497, 0x49A, 0x49C, 0x49F, 0x4A1, 0x4A4,
    0x4A6, 0x4A9, 0x4AB, 0x4AE, 0x4B0, 0x4B3, 0x4B5, 0x4B8, 0x4BA, 0x4BC, 0x4BF, 0x4C1, 0x4C4, 0x4C6, 0x4C9, 0x4CB,
    0x4CE, 0x4D0, 0x4D3, 0x4D5, 0x4D7, 0x4DA, 0x4DC, 0x4DF, 0x4E1, 0x4E4, 0x4E6, 0x4E8, 0x4EB, 0x4ED, 0x4F0, 0x4F2,
    0x4F5, 0x4F7, 0x4F9, 0x4FC, 0x4FE, 0x501, 0x503, 0x505, 0x508, 0x50A, 0x50D, 0x50F, 0x511, 0x514, 0x516, 0x519,
    0x51B, 0x51D, 0x520, 0x522, 0x524, 0x527, 0x529, 0x52C, 0x52E, 0x530, 0x533, 0x535, 0x537, 0x53A, 0x53C, 0x53E,
    0x541, 0x543, 0x546, 0x548, 0x54A, 0x54D, 0x54F, 0x551, 0x554, 0x556, 0x558, 0x55B, 0x55D, 0x55F, 0x562, 0x564,
    0x566, 0x568, 0x56B, 0x56D, 0x56F, 0x572, 0x574, 0x576, 0x579, 0x57B, 0x57D, 0x580, 0x582, 0x584, 0x586, 0x589,
    0x58B, 0x58D, 0x590, 0x592, 0x594, 0x596, 0x599, 0x59B, 0x59D, 0x5A0, 0x5A2, 0x5A4, 0x5A6, 0x5A9, 0x5AB, 0x5AD,
    0x5AF, 0x5B2, 0x5B4, 0x5B6, 0x5B8, 0x5BB, 0x5BD, 0x5BF, 0x5C1, 0x5C4, 0x5C6, 0x5C8, 0x5CA, 0x5CD, 0x5CF, 0x5D1,
    0x5D3, 0x5D5, 0x5D8, 0x5DA, 0x5DC, 0x5DE, 0x5E1, 0x5E3, 0x5E5, 0x5E7, 0x5E9, 0x5EC, 0x5EE, 0x5F0, 0x5F2, 0x5F4,
    0x5F7, 0x5F9, 0x5FB, 0x5FD, 0x5FF, 0x602, 0x604, 0x606, 0x608, 0x60A, 0x60C, 0x60F, 0x611, 0x613, 0x615, 0x617,
    0x619, 0x61C, 0x61E, 0x620, 0x622, 0x624, 0x626, 0x629, 0x62B, 0x62D, 0x62F, 0x631, 0x633, 0x635, 0x638, 0x63A,
    0x63C, 0x63E, 0x640, 0x642, 0x644, 0x646, 0x649, 0x64B, 0x64D, 0x64F, 0x651, 0x653, 0x655, 0x657, 0x65A, 0x65C,
    0x65E, 0x660, 0x662, 0x664, 0x666, 0x668, 0x66A, 0x66C, 0x66F, 0x671, 0x673, 0x675, 0x677, 0x679, 0x67B, 0x67D,
    0x67F, 0x681, 0x683, 0x685, 0x688, 0x68A, 0x68C, 0x68E, 0x690, 0x692, 0x694, 0x696, 0x698, 0x69A, 0x69C, 0x69E,
    0x6A0, 0x6A2, 0x6A4, 0x6A6, 0x6A8, 0x6AB, 0x6AD, 0x6AF, 0x6B1, 0x6B3, 0x6B5, 0x6B7, 0x6B9, 0x6BB, 0x6BD, 0x6BF,
    0x6C1, 0x6C3, 0x6C5, 0x6C7, 0x6C9, 0x6CB, 0x6CD, 0x6CF, 0x6D1, 0x6D3, 0x6D5, 0x6D7, 0x6D9, 0x6DB, 0x6DD, 0x6DF,
    0x6E1, 0x6E3, 0x6E5, 0x6E7, 0x6E9, 0x6EB, 0x6ED, 0x6EF, 0x6F1, 0x6F3, 0x6F5, 0x6F7, 0x6F9, 0x6FB, 0x6FD, 0x6FF,
    0x701, 0x703, 0x705, 0x707, 0x709, 0x70B, 0x70C, 0x70E, 0x710, 0x712, 0x714, 0x716, 0x718, 0x71A, 0x71C, 0x71E,
    0x720, 0x722, 0x724, 0x726, 0x728, 0x72A, 0x72C, 0x72E, 0x72F, 0x731, 0x733, 0x735, 0x737, 0x739, 0x73B, 0x73D,
    0x73F, 0x741, 0x743, 0x745, 0x746, 0x748, 0x74A, 0x74C, 0x74E, 0x750, 0x752, 0x754, 0x756, 0x758, 0x759, 0x75B,
    0x75D, 0x75F, 0x761, 0x763, 0x765, 0x767, 0x769, 0x76A, 0x76C, 0x76E, 0x770, 0x772, 0x774, 0x776, 0x778, 0x779,
    0x77B, 0x77D, 0x77F, 0x781, 0x783, 0x785, 0x786, 0x788, 0x78A, 0x78C, 0x78E, 0x790, 0x791, 0x793, 0x795, 0x797,
    0x799, 0x79B, 0x79D, 0x79E, 0x7A0, 0x7A2, 0x7A4, 0x7A6, 0x7A7, 0x7A9, 0x7AB, 0x7AD, 0x7AF, 0x7B1, 0x7B2, 0x7B4,
    0x7B6, 0x7B8, 0x7BA, 0x7BB, 0x7BD, 0x7BF, 0x7C1, 0x7C3, 0x7C4, 0x7C6, 0x7C8, 0x7CA, 0x7CC, 0x7CD, 0x7CF, 0x7D1,
    0x7D3, 0x7D5, 0x7D6, 0x7D8, 0x7DA, 0x7DC, 0x7DE, 0x7DF, 0x7E1, 0x7E3, 0x7E5, 0x7E6, 0x7E8, 0x7EA, 0x7EC, 0x7ED,
    0x7EF, 0x7F1, 0x7F3, 0x7F5, 0x7F6, 0x7F8, 0x7FA, 0x7FC, 0x7FD, 0x7FF, 0x801, 0x803, 0x804, 0x806, 0x808, 0x80A,
    0x80B, 0x80D, 0x80F, 0x810, 0x812, 0x814, 0x816, 0x817, 0x819, 0x81B, 0x81D, 0x81E, 0x820, 0x822, 0x823, 0x825,
    0x827, 0x829, 0x82A, 0x82C, 0x82E, 0x82F, 0x831, 0x833, 0x835, 0x836, 0x838, 0x83A, 0x83B, 0x83D, 0x83F, 0x841,
    0x842, 0x844, 0x846, 0x847, 0x849, 0x84B, 0x84C, 0x84E, 0x850, 0x851, 0x853, 0x855, 0x856, 0x858, 0x85A, 0x85B,
    0x85D, 0x85F, 0x860, 0x862, 0x864, 0x865, 0x867, 0x869, 0x86A, 0x86C, 0x86E, 0x86F, 0x871, 0x873, 0x874, 0x876,
    0x878, 0x879, 0x87B, 0x87D, 0x87E, 0x880, 0x881, 0x883, 0x885, 0x886, 0x888, 0x88A, 0x88B, 0x88D, 0x88F, 0x890,
    0x892, 0x893, 0x895, 0x897, 0x898, 0x89A, 0x89C, 0x89D, 0x89F, 0x8A0, 0x8A2, 0x8A4, 0x8A5, 0x8A7, 0x8A8, 0x8AA,
    0x8AC, 0x8AD, 0x8AF, 0x8B0, 0x8B2, 0x8B4, 0x8B5, 0x8B7, 0x8B8, 0x8BA, 0x8BC, 0x8BD, 0x8BF, 0x8C0, 0x8C2, 0x8C4,
    0x8C5, 0x8C7, 0x8C8, 0x8CA, 0x8CB, 0x8CD, 0x8CF, 0x8D0, 0x8D2, 0x8D3, 0x8D5, 0x8D6, 0x8D8, 0x8DA, 0x8DB, 0x8DD,
    0x8DE, 0x8E0, 0x8E1, 0x8E3, 0x8E4, 0x8E6, 0x8E8, 0x8E9, 0x8EB, 0x8EC, 0x8EE, 0x8EF, 0x8F1, 0x8F2, 0x8F4, 0x8F5,
    0x8F7, 0x8F9, 0x8FA, 0x8FC, 0x8FD, 0x8FF, 0x900, 0x902, 0x903, 0x905, 0x906, 0x908, 0x909, 0x90B, 0x90C, 0x90E,
    0x90F, 0x911, 0x912, 0x914, 0x916, 0x917, 0x919, 0x91A, 0x91C, 0x91D, 0x91F, 0x920, 0x922, 0x923, 0x925, 0x926,
    0x928, 0x929, 0x92B, 0x92C, 0x92E, 0x92F, 0x931, 0x932, 0x934, 0x935, 0x936, 0x938, 0x939, 0x93B, 0x93C, 0x93E,
    0x93F, 0x941, 0x942, 0x944, 0x945, 0x947, 0x948, 0x94A, 0x94B, 0x94D, 0x94E, 0x950, 0x951, 0x952, 0x954, 0x955,
    0x957, 0x958, 0x95A, 0x95B, 0x95D, 0x95E, 0x960, 0x961, 0x962, 0x964, 0x965, 0x967, 0x968, 0x96A, 0x96B, 0x96D,
    0x96E, 0x96F, 0x971, 0x972, 0x974, 0x975, 0x977, 0x978, 0x979, 0x97B, 0x97C, 0x97E, 0x97F, 0x981, 0x982, 0x983,
    0x985, 0x986, 0x988, 0x989, 0x98A, 0x98C, 0x98D, 0x98F, 0x990, 0x992, 0x993, 0x994, 0x996, 0x997, 0x999, 0x99A,
    0x99B, 0x99D, 0x99E, 0x9A0, 0x9A1, 0x9A2, 0x9A4, 0x9A5, 0x9A6, 0x9A8, 0x9A9, 0x9AB, 0x9AC, 0x9AD, 0x9AF, 0x9B0,
    0x9B2, 0x9B3, 0x9B4, 0x9B6, 0x9B7, 0x9B8, 0x9BA, 0x9BB, 0x9BD, 0x9BE, 0x9BF, 0x9C1, 0x9C2, 0x9C3, 0x9C5, 0x9C6,
    0x9C7, 0x9C9, 0x9CA, 0x9CC, 0x9CD, 0x9CE, 0x9D0, 0x9D1, 0x9D2, 0x9D4, 0x9D5, 0x9D6, 0x9D8, 0x9D9, 0x9DA, 0x9DC,
    0x9DD, 0x9DE, 0x9E0, 0x9E1, 0x9E2, 0x9E4, 0x9E5, 0x9E6, 0x9E8, 0x9E9, 0x9EA, 0x9EC, 0x9ED, 0x9EE, 0x9F0, 0x9F1,
    0x9F2, 0x9F4, 0x9F5, 0x9F6, 0x9F8, 0x9F9, 0x9FA, 0x9FC, 0x9FD, 0x9FE, 0xA00, 0xA01, 0xA02, 0xA04, 0xA05, 0xA06,
    0xA07, 0xA09, 0xA0A, 0xA0B, 0xA0D, 0xA0E, 0xA0F, 0xA11, 0xA12, 0xA13, 0xA14, 0xA16, 0xA17, 0xA18, 0xA1A, 0xA1B,
    0xA1C, 0xA1D, 0xA1F, 0xA20, 0xA21, 0xA23, 0xA24, 0xA25, 0xA26, 0xA28, 0xA29, 0xA2A, 0xA2C, 0xA2D, 0xA2E, 0xA2F,
    0xA31, 0xA32, 0xA33, 0xA34, 0xA36, 0xA37, 0xA38, 0xA3A, 0xA3B, 0xA3C, 0xA3D, 0xA3F, 0xA40, 0xA41, 0xA42, 0xA44,
    0xA45, 0xA46, 0xA47, 0xA49, 0xA4A, 0xA4B, 0xA4C, 0xA4E, 0xA4F, 0xA50, 0xA51, 0xA53, 0xA54, 0xA55, 0xA56, 0xA58,
    0xA59, 0xA5A, 0xA5B, 0xA5C, 0xA5E, 0xA5F, 0xA60, 0xA61, 0xA63, 0xA64, 0xA65, 0xA66, 0xA67, 0xA69, 0xA6A, 0xA6B,
    0xA6C, 0xA6E, 0xA6F, 0xA70, 0xA71, 0xA72, 0xA74, 0xA75, 0xA76, 0xA77, 0xA79, 0xA7A, 0xA7B, 0xA7C, 0xA7D, 0xA7F,
    0xA80, 0xA81, 0xA82, 0xA83, 0xA85, 0xA86, 0xA87, 0xA88, 0xA89, 0xA8B, 0xA8C, 0xA8D, 0xA8E, 0xA8F, 0xA91, 0xA92,
    0xA93, 0xA94, 0xA95, 0xA96, 0xA98, 0xA99, 0xA9A, 0xA9B, 0xA9C, 0xA9E, 0xA9F, 0xAA0, 0xAA1, 0xAA2, 0xAA3, 0xAA5,
    0xAA6, 0xAA7, 0xAA8, 0xAA9, 0xAAA, 0xAAC, 0xAAD, 0xAAE, 0xAAF, 0xAB0, 0xAB1, 0xAB3, 0xAB4, 0xAB5, 0xAB6, 0xAB7,
    0xAB8, 0xAB9, 0xABB, 0xABC, 0xABD, 0xABE, 0xABF, 0xAC0, 0xAC2, 0xAC3, 0xAC4, 0xAC5, 0xAC6, 0xAC7, 0xAC8, 0xACA,
    0xACB, 0xACC, 0xACD, 0xACE, 0xACF, 0xAD0, 0xAD1, 0xAD3, 0xAD4, 0xAD5, 0xAD6, 0xAD7, 0xAD8, 0xAD9, 0xADB, 0xADC,
    0xADD, 0xADE, 0xADF, 0xAE0, 0xAE1, 0xAE2, 0xAE3, 0xAE5, 0xAE6, 0xAE7, 0xAE8, 0xAE9, 0xAEA, 0xAEB, 0xAEC, 0xAEE,
    0xAEF, 0xAF0, 0xAF1, 0xAF2, 0xAF3, 0xAF4, 0xAF5, 0xAF6, 0xAF7, 0xAF9, 0xAFA, 0xAFB, 0xAFC, 0xAFD, 0xAFE, 0xAFF,
    0xB00, 0xB01, 0xB02, 0xB04, 0xB05, 0xB06, 0xB07, 0xB08, 0xB09, 0xB0A, 0xB0B, 0xB0C, 0xB0D, 0xB0E, 0xB0F, 0xB11,
    0xB12, 0xB13, 0xB14, 0xB15, 0xB16, 0xB17, 0xB18, 0xB19, 0xB1A, 0xB1B, 0xB1C, 0xB1D, 0xB1E, 0xB20, 0xB21, 0xB22,
    0xB23, 0xB24, 0xB25, 0xB26, 0xB27, 0xB28, 0xB29, 0xB2A, 0xB2B, 0xB2C, 0xB2D, 0xB2E, 0xB2F, 0xB30, 0xB32, 0xB33,
    0xB34, 0xB35, 0xB36, 0xB37, 0xB38, 0xB39, 0xB3A, 0xB3B, 0xB3C, 0xB3D, 0xB3E, 0xB3F, 0xB40, 0xB41, 0xB42, 0xB43,
    0xB44, 0xB45, 0xB46, 0xB47, 0xB48, 0xB49, 0xB4B, 0xB4C, 0xB4D, 0xB4E, 0xB4F, 0xB50, 0xB51, 0xB52, 0xB53, 0xB54,
    0xB55, 0xB56, 0xB57, 0xB58, 0xB59, 0xB5A, 0xB5B, 0xB5C, 0xB5D, 0xB5E, 0xB5F, 0xB60, 0xB61, 0xB62, 0xB63, 0xB64,
    0xB65, 0xB66, 0xB67, 0xB68, 0xB69, 0xB6A, 0xB6B, 0xB6C, 0xB6D, 0xB6E, 0xB6F, 0xB70, 0xB71, 0xB72, 0xB73, 0xB74,
    0xB75, 0xB76, 0xB77, 0xB78, 0xB79, 0xB7A, 0xB7B, 0xB7C, 0xB7D, 0xB7E, 0xB7F, 0xB80, 0xB81, 0xB82, 0xB83, 0xB84,
    0xB85, 0xB86, 0xB87, 0xB88, 0xB89, 0xB8A, 0xB8B, 0xB8C, 0xB8D, 0xB8E, 0xB8F, 0xB8F, 0xB90, 0xB91, 0xB92, 0xB93,
    0xB94, 0xB95, 0xB96, 0xB97, 0xB98, 0xB99, 0xB9A, 0xB9B, 0xB9C, 0xB9D, 0xB9E, 0xB9F, 0xBA0, 0xBA1, 0xBA2, 0xBA3,
    0xBA4, 0xBA5, 0xBA6, 0xBA7, 0xBA7, 0xBA8, 0xBA9, 0xBAA, 0xBAB, 0xBAC, 0xBAD, 0xBAE, 0xBAF, 0xBB0, 0xBB1, 0xBB2,
    0xBB3, 0xBB4, 0xBB5, 0xBB6, 0xBB7, 0xBB8, 0xBB8, 0xBB9, 0xBBA, 0xBBB, 0xBBC, 0xBBD, 0xBBE, 0xBBF, 0xBC0, 0xBC1,
    0xBC2, 0xBC3, 0xBC4, 0xBC5, 0xBC5, 0xBC6, 0xBC7, 0xBC8, 0xBC9, 0xBCA, 0xBCB, 0xBCC, 0xBCD, 0xBCE, 0xBCF, 0xBD0,
    0xBD1, 0xBD1, 0xBD2, 0xBD3, 0xBD4, 0xBD5, 0xBD6, 0xBD7, 0xBD8, 0xBD9, 0xBDA, 0xBDB, 0xBDB, 0xBDC, 0xBDD, 0xBDE,
    0xBDF, 0xBE0, 0xBE1, 0xBE2, 0xBE3, 0xBE4, 0xBE4, 0xBE5, 0xBE6, 0xBE7, 0xBE8, 0xBE9, 0xBEA, 0xBEB, 0xBEC, 0xBED,
    0xBED, 0xBEE, 0xBEF, 0xBF0, 0xBF1, 0xBF2, 0xBF3, 0xBF4, 0xBF5, 0xBF5, 0xBF6, 0xBF7, 0xBF8, 0xBF9, 0xBFA, 0xBFB,
    0xBFC, 0xBFC, 0xBFD, 0xBFE, 0xBFF, 0xC00, 0xC01, 0xC02, 0xC03, 0xC03, 0xC04, 0xC05, 0xC06, 0xC07, 0xC08, 0xC09,
    0xC0A, 0xC0A, 0xC0B, 0xC0C, 0xC0D, 0xC0E, 0xC0F, 0xC10, 0xC10, 0xC11, 0xC12, 0xC13, 0xC14, 0xC15, 0xC16, 0xC16,
    0xC17, 0xC18, 0xC19, 0xC1A, 0xC1B, 0xC1C, 0xC1C, 0xC1D, 0xC1E, 0xC1F, 0xC20, 0xC21, 0xC21, 0xC22, 0xC23, 0xC24,
    0xC25, 0xC26, 0xC27, 0xC27, 0xC28, 0xC29, 0xC2A, 0xC2B, 0xC2C, 0xC2C, 0xC2D, 0xC2E, 0xC2F, 0xC30, 0xC31, 0xC31,
    0xC32, 0xC33, 0xC34, 0xC35, 0xC36, 0xC36, 0xC37, 0xC38, 0xC39, 0xC3A, 0xC3B, 0xC3B, 0xC3C, 0xC3D, 0xC3E, 0xC3F,
    0xC3F, 0xC40, 0xC41, 0xC42, 0xC43, 0xC44, 0xC44, 0xC45, 0xC46, 0xC47, 0xC48, 0xC48, 0xC49, 0xC4A, 0xC4B, 0xC4C,
    0xC4D, 0xC4D, 0xC4E, 0xC4F, 0xC50, 0xC51, 0xC51, 0xC52, 0xC53, 0xC54, 0xC55, 0xC55, 0xC56, 0xC57, 0xC58, 0xC59,
    0xC59, 0xC5A, 0xC5B, 0xC5C, 0xC5D, 0xC5D, 0xC5E, 0xC5F, 0xC60, 0xC61, 0xC61, 0xC62, 0xC63, 0xC64, 0xC64, 0xC65,
    0xC66, 0xC67, 0xC68, 0xC68, 0xC69, 0xC6A, 0xC6B, 0xC6C, 0xC6C, 0xC6D, 0xC6E, 0xC6F, 0xC6F, 0xC70, 0xC71, 0xC72,
    0xC73, 0xC73, 0xC74, 0xC75, 0xC76, 0xC76, 0xC77, 0xC78, 0xC79, 0xC7A, 0xC7A, 0xC7B, 0xC7C, 0xC7D, 0xC7D, 0xC7E,
    0xC7F, 0xC80, 0xC80, 0xC81, 0xC82, 0xC83, 0xC83, 0xC84, 0xC85, 0xC86, 0xC87, 0xC87, 0xC88, 0xC89, 0xC8A, 0xC8A,
    0xC8B, 0xC8C, 0xC8D, 0xC8D, 0xC8E, 0xC8F, 0xC90, 0xC90, 0xC91, 0xC92, 0xC93, 0xC93, 0xC94, 0xC95, 0xC96, 0xC96,
    0xC97, 0xC98, 0xC99, 0xC99, 0xC9A, 0xC9B, 0xC9C, 0xC9C, 0xC9D, 0xC9E, 0xC9F, 0xC9F, 0xCA0, 0xCA1, 0xCA1, 0xCA2,
    0xCA3, 0xCA4, 0xCA4, 0xCA5, 0xCA6, 0xCA7, 0xCA7, 0xCA8, 0xCA9, 0xCAA, 0xCAA, 0xCAB, 0xCAC, 0xCAC, 0xCAD, 0xCAE,
    0xCAF, 0xCAF, 0xCB0, 0xCB1, 0xCB2, 0xCB2, 0xCB3, 0xCB4, 0xCB4, 0xCB5, 0xCB6, 0xCB7, 0xCB7, 0xCB8, 0xCB9, 0xCB9,
    0xCBA, 0xCBB, 0xCBC, 0xCBC, 0xCBD, 0xCBE, 0xCBE, 0xCBF, 0xCC0, 0xCC1, 0xCC1, 0xCC2, 0xCC3, 0xCC3, 0xCC4, 0xCC5,
    0xCC6, 0xCC6, 0xCC7, 0xCC8, 0xCC8, 0xCC9, 0xCCA, 0xCCA, 0xCCB, 0xCCC, 0xCCD, 0xCCD, 0xCCE, 0xCCF, 0xCCF, 0xCD0,
    0xCD1, 0xCD1, 0xCD2, 0xCD3, 0xCD4, 0xCD4, 0xCD5, 0xCD6, 0xCD6, 0xCD7, 0xCD8, 0xCD8, 0xCD9, 0xCDA, 0xCDA, 0xCDB,
    0xCDC, 0xCDC, 0xCDD, 0xCDE, 0xCDF, 0xCDF, 0xCE0, 0xCE1, 0xCE1, 0xCE2, 0xCE3, 0xCE3, 0xCE4, 0xCE5, 0xCE5, 0xCE6,
    0xCE7, 0xCE7, 0xCE8, 0xCE9, 0xCE9, 0xCEA, 0xCEB, 0xCEB, 0xCEC, 0xCED, 0xCED, 0xCEE, 0xCEF, 0xCEF, 0xCF0, 0xCF1,
    0xCF1, 0xCF2, 0xCF3, 0xCF3, 0xCF4, 0xCF5, 0xCF5, 0xCF6, 0xCF7, 0xCF7, 0xCF8, 0xCF9, 0xCF9, 0xCFA, 0xCFB, 0xCFB,
    0xCFC, 0xCFD, 0xCFD, 0xCFE, 0xCFF, 0xCFF, 0xD00, 0xD01, 0xD01, 0xD02, 0xD03, 0xD03, 0xD04, 0xD05, 0xD05, 0xD06,
    0xD07, 0xD07, 0xD08, 0xD09, 0xD09, 0xD0A, 0xD0A, 0xD0B, 0xD0C, 0xD0C, 0xD0D, 0xD0E, 0xD0E, 0xD0F, 0xD10, 0xD10,
    0xD11, 0xD12, 0xD12, 0xD13, 0xD13, 0xD14, 0xD15, 0xD15, 0xD16, 0xD17, 0xD17, 0xD18, 0xD19, 0xD19, 0xD1A, 0xD1A,
    0xD1B, 0xD1C, 0xD1C, 0xD1D, 0xD1E, 0xD1E, 0xD1F, 0xD1F, 0xD20, 0xD21, 0xD21, 0xD22, 0xD23, 0xD23, 0xD24, 0xD25,
    0xD25, 0xD26, 0xD26, 0xD27, 0xD28, 0xD28, 0xD29, 0xD29, 0xD2A, 0xD2B, 0xD2B, 0xD2C, 0xD2D, 0xD2D, 0xD2E, 0xD2E,
    0xD2F, 0xD30, 0xD30, 0xD31, 0xD32, 0xD32, 0xD33, 0xD33, 0xD34, 0xD35, 0xD35, 0xD36, 0xD36, 0xD37, 0xD38, 0xD38};

static const unsigned short CutoffMul6581_44100Hz[] = { // generated by curvegen.c
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081, 0x081,
    0x081, 0x086, 0x08B, 0x08F, 0x094, 0x099, 0x09D, 0x0A2, 0x0A6, 0x0AB, 0x0B0, 0x0B4, 0x0B9, 0x0BE, 0x0C2, 0x0C7,
    0x0CB, 0x0D0, 0x0D5, 0x0D9, 0x0DE, 0x0E2, 0x0E7, 0x0EB, 0x0F0, 0x0F5, 0x0F9, 0x0FE, 0x102, 0x107, 0x10B, 0x110,
    0x114, 0x119, 0x11D, 0x122, 0x126, 0x12B, 0x12F, 0x134, 0x138, 0x13D, 0x141, 0x146, 0x14A, 0x14F, 0x153, 0x157,
    0x15C, 0x160, 0x165, 0x169, 0x16E, 0x172, 0x176, 0x17B, 0x17F, 0x183, 0x188, 0x18C, 0x191, 0x195, 0x199, 0x19E,
    0x1A2, 0x1A6, 0x1AB, 0x1AF, 0x1B3, 0x1B8, 0x1BC, 0x1C0, 0x1C5, 0x1C9, 0x1CD, 0x1D2, 0x1D6, 0x1DA, 0x1DE, 0x1E3,
    0x1E7, 0x1EB, 0x1EF, 0x1F4, 0x1F8, 0x1FC, 0x200, 0x205, 0x209, 0x20D, 0x211, 0x215, 0x21A, 0x21E, 0x222, 0x226,
    0x22A, 0x22F, 0x233, 0x237, 0x23B, 0x23F, 0x243, 0x248, 0x24C, 0x250, 0x254, 0x258, 0x25C, 0x260, 0x265, 0x269,
    0x26D, 0x271, 0x275, 0x279, 0x27D, 0x281, 0x285, 0x289, 0x28D, 0x292, 0x296, 0x29A, 0x29E, 0x2A2, 0x2A6, 0x2AA,
    0x2AE, 0x2B2, 0x2B6, 0x2BA, 0x2BE, 0x2C2, 0x2C6, 0x2CA, 0x2CE, 0x2D2, 0x2D6, 0x2DA, 0x2DE, 0x2E2, 0x2E6, 0x2EA,
    0x2EE, 0x2F2, 0x2F6, 0x2FA, 0x2FD, 0x301, 0x305, 0x309, 0x30D, 0x311, 0x315, 0x319, 0x31D, 0x321, 0x325, 0x328,
    0x32C, 0x330, 0x334, 0x338, 0x33C, 0x340, 0x344, 0x347, 0x34B, 0x34F, 0x353, 0x357, 0x35B, 0x35E, 0x362, 0x366,
    0x36A, 0x36E, 0x371, 0x375, 0x379, 0x37D, 0x381, 0x384, 0x388, 0x38C, 0x390, 0x393, 0x397, 0x39B, 0x39F, 0x3A2,
    0x3A6, 0x3AA, 0x3AE, 0x3B1, 0x3B5, 0x3B9, 0x3BD, 0x3C0, 0x3C4, 0x3C8, 0x3CB, 0x3CF, 0x3D3, 0x3D6, 0x3DA, 0x3DE,
    0x3E1, 0x3E5, 0x3E9, 0x3EC, 0x3F0, 0x3F4, 0x3F7, 0x3FB, 0x3FF, 0x402, 0x406, 0x409, 0x40D, 0x411, 0x414, 0x418,
    0x41B, 0x41F, 0x423, 0x426, 0x42A, 0x42D, 0x431, 0x435, 0x438, 0x43C, 0x43F, 0x443, 0x446, 0x44A, 0x44D, 0x451,
    0x455, 0x458, 0x45C, 0x45F, 0x463, 0x466, 0x46A, 0x46D, 0x471, 0x474, 0x478, 0x47B, 0x47F, 0x482, 0x486, 0x489,
    0x48C, 0x490, 0x493, 0x497, 0x49A, 0x49E, 0x4A1, 0x4A5, 0x4A8, 0x4AB, 0x4AF, 0x4B2, 0x4B6, 0x4B9, 0x4BD, 0x4C0,
    0x4C3, 0x4C7, 0x4CA, 0x4CE, 0x4D1, 0x4D4, 0x4D8, 0x4DB, 0x4DE, 0x4E2, 0x4E5, 0x4E8, 0x4EC, 0x4EF, 0x4F3, 0x4F6,
    0x4F9, 0x4FD, 0x500, 0x503, 0x507, 0x50A, 0x50D, 0x510, 0x514, 0x517, 0x51A, 0x51E, 0x521, 0x524, 0x528, 0x52B,
    0x52E, 0x531, 0x535, 0x538, 0x53B, 0x53E, 0x542, 0x545, 0x548, 0x54B, 0x54F, 0x552, 0x555, 0x558, 0x55B, 0x55F,
    0x562, 0x565, 0x568, 0x56C, 0x56F, 0x572, 0x575, 0x578, 0x57B, 0x57F, 0x582, 0x585, 0x588, 0x58B, 0x58F, 0x592,
    0x595, 0x598, 0x59B, 0x59E, 0x5A1, 0x5A5, 0x5A8, 0x5AB, 0x5AE, 0x5B1, 0x5B4, 0x5B7, 0x5BA, 0x5BD, 0x5C1, 0x5C4,
    0x5C7, 0x5CA, 0x5CD, 0x5D0, 0x5D3, 0x5D6, 0x5D9, 0x5DC, 0x5DF, 0x5E2, 0x5E5, 0x5E9, 0x5EC, 0x5EF, 0x5F2, 0x5F5,
    0x5F8, 0x5FB, 0x5FE, 0x601, 0x604, 0x607, 0x60A, 0x60D, 0x610, 0x613, 0x616, 0x619, 0x61C, 0x61F, 0x622, 0x625,
    0x628, 0x62B, 0x62E, 0x631, 0x634, 0x637, 0x63A, 0x63D, 0x640, 0x643, 0x645, 0x648, 0x64B, 0x64E, 0x651, 0x654,
    0x657, 0x65A, 0x65D, 0x660, 0x663, 0x666, 0x669, 0x66B, 0x66E, 0x671, 0x674, 0x677, 0x67A, 0x67D, 0x680, 0x682,
    0x685, 0x688, 0x68B, 0x68E, 0x691, 0x694, 0x696, 0x699, 0x69C, 0x69F, 0x6A2, 0x6A5, 0x6A7, 0x6AA, 0x6AD, 0x6B0,
    0x6B3, 0x6B6, 0x6B8, 0x6BB, 0x6BE, 0x6C1, 0x6C4, 0x6C6, 0x6C9, 0x6CC, 0x6CF, 0x6D2, 0x6D4, 0x6D7, 0x6DA, 0x6DD,
    0x6DF, 0x6E2, 0x6E5, 0x6E8, 0x6EA, 0x6ED, 0x6F0, 0x6F3, 0x6F5, 0x6F8, 0x6FB, 0x6FE, 0x700, 0x703, 0x706, 0x708,
    0x70B, 0x70E, 0x711, 0x713, 0x716, 0x719, 0x71B, 0x71E, 0x721, 0x723, 0x726, 0x729, 0x72B, 0x72E, 0x731, 0x733,
    0x736, 0x739, 0x73B, 0x73E, 0x741, 0x743, 0x746, 0x749, 0x74B, 0x74E, 0x750, 0x753, 0x756, 0x758, 0x75B, 0x75E,
    0x760, 0x763, 0x765, 0x768, 0x76B, 0x76D, 0x770, 0x772, 0x775, 0x778, 0x77A, 0x77D, 0x77F, 0x782, 0x784, 0x787,
    0x78A, 0x78C, 0x78F, 0x791, 0x794, 0x796, 0x799, 0x79B, 0x79E, 0x7A0, 0x7A3, 0x7A5, 0x7A8, 0x7AB, 0x7AD, 0x7B0,
    0x7B2, 0x7B5, 0x7B7, 0x7BA, 0x7BC, 0x7BF, 0x7C1, 0x7C4, 0x7C6, 0x7C9, 0x7CB, 0x7CE, 0x7D0, 0x7D2, 0x7D5, 0x7D7,
    0x7DA, 0x7DC, 0x7DF, 0x7E1, 0x7E4, 0x7E6, 0x7E9, 0x7EB, 0x7ED, 0x7F0, 0x7F2, 0x7F5, 0x7F7, 0x7FA, 0x7FC, 0x7FF,
    0x801, 0x803, 0x806, 0x808, 0x80B, 0x80D, 0x80F, 0x812, 0x814, 0x817, 0x819, 0x81B, 0x81E, 0x820, 0x823, 0x825,
    0x827, 0x82A, 0x82C, 0x82E, 0x831, 0x833, 0x835, 0x838, 0x83A, 0x83D, 0x83F, 0x841, 0x844, 0x846, 0x848, 0x84B,
    0x84D, 0x84F, 0x852, 0x854, 0x856, 0x858, 0x85B, 0x85D, 0x85F, 0x862, 0x864, 0x866, 0x869, 0x86B, 0x86D, 0x86F,
    0x872, 0x874, 0x876, 0x879, 0x87B, 0x87D, 0x87F, 0x882, 0x884, 0x886, 0x888, 0x88B, 0x88D, 0x88F, 0x892, 0x894,
    0x896, 0x898, 0x89A, 0x89D, 0x89F, 0x8A1, 0x8A3, 0x8A6, 0x8A8, 0x8AA, 0x8AC, 0x8AE, 0x8B1, 0x8B3, 0x8B5, 0x8B7,
    0x8BA, 0x8BC, 0x8BE, 0x8C0, 0x8C2, 0x8C4, 0x8C7, 0x8C9, 0x8CB, 0x8CD, 0x8CF, 0x8D2, 0x8D4, 0x8D6, 0x8D8, 0x8DA,
    0x8DC, 0x8DF, 0x8E1, 0x8E3, 0x8E5, 0x8E7, 0x8E9, 0x8EB, 0x8EE, 0x8F0, 0x8F2, 0x8F4, 0x8F6, 0x8F8, 0x8FA, 0x8FC,
    0x8FF, 0x901, 0x903, 0x905, 0x907, 0x909, 0x90B, 0x90D, 0x90F, 0x912, 0x914, 0x916, 0x918, 0x91A, 0x91C, 0x91E,
    0x920, 0x922, 0x924, 0x926, 0x928, 0x92B, 0x92D, 0x92F, 0x931, 0x933, 0x935, 0x937, 0x939, 0x93B, 0x93D, 0x93F,
    0x941, 0x943, 0x945, 0x947, 0x949, 0x94B, 0x94D, 0x94F, 0x951, 0x953, 0x955, 0x957, 0x959, 0x95B, 0x95D, 0x95F,
    0x961, 0x963, 0x965, 0x967, 0x969, 0x96B, 0x96D, 0x96F, 0x971, 0x973, 0x975, 0x977, 0x979, 0x97B, 0x97D, 0x97F,
    0x981, 0x983, 0x985, 0x987, 0x989, 0x98B, 0x98D, 0x98F, 0x991, 0x993, 0x995, 0x997, 0x999, 0x99B, 0x99C, 0x99E,
    0x9A0, 0x9A2, 0x9A4, 0x9A6, 0x9A8, 0x9AA, 0x9AC, 0x9AE, 0x9B0, 0x9B2, 0x9B3, 0x9B5, 0x9B7, 0x9B9, 0x9BB, 0x9BD,
    0x9BF, 0x9C1, 0x9C3, 0x9C5, 0x9C6, 0x9C8, 0x9CA, 0x9CC, 0x9CE, 0x9D0, 0x9D2, 0x9D4, 0x9D5, 0x9D7, 0x9D9, 0x9DB,
    0x9DD, 0x9DF, 0x9E1, 0x9E2, 0x9E4, 0x9E6, 0x9E8, 0x9EA, 0x9EC, 0x9ED, 0x9EF, 0x9F1, 0x9F3, 0x9F5, 0x9F7, 0x9F8,
    0x9FA, 0x9FC, 0x9FE, 0xA00, 0xA02, 0xA03, 0xA05, 0xA07, 0xA09, 0xA0B, 0xA0C, 0xA0E, 0xA10, 0xA12, 0xA14, 0xA15,
    0xA17, 0xA19, 0xA1B, 0xA1C, 0xA1E, 0xA20, 0xA22, 0xA24, 0xA25, 0xA27, 0xA29, 0xA2B, 0xA2C, 0xA2E, 0xA30, 0xA32,
    0xA33, 0xA35, 0xA37, 0xA39, 0xA3A, 0xA3C, 0xA3E, 0xA40, 0xA41, 0xA43, 0xA45, 0xA47, 0xA48, 0xA4A, 0xA4C, 0xA4E,
    0xA4F, 0xA51, 0xA53, 0xA54, 0xA56, 0xA58, 0xA5A, 0xA5B, 0xA5D, 0xA5F, 0xA60, 0xA62, 0xA64, 0xA65, 0xA67, 0xA69,
    0xA6B, 0xA6C, 0xA6E, 0xA70, 0xA71, 0xA73, 0xA75, 0xA76, 0xA78, 0xA7A, 0xA7B, 0xA7D, 0xA7F, 0xA80, 0xA82, 0xA84,
    0xA85, 0xA87, 0xA89, 0xA8A, 0xA8C, 0xA8E, 0xA8F, 0xA91, 0xA92, 0xA94, 0xA96, 0xA97, 0xA99, 0xA9B, 0xA9C, 0xA9E,
    0xAA0, 0xAA1, 0xAA3, 0xAA4, 0xAA6, 0xAA8, 0xAA9, 0xAAB, 0xAAC, 0xAAE, 0xAB0, 0xAB1, 0xAB3, 0xAB5, 0xAB6, 0xAB8,
    0xAB9, 0xABB, 0xABC, 0xABE, 0xAC0, 0xAC1, 0xAC3, 0xAC4, 0xAC6, 0xAC8, 0xAC9, 0xACB, 0xACC, 0xACE, 0xACF, 0xAD1,
    0xAD3, 0xAD4, 0xAD6, 0xAD7, 0xAD9, 0xADA, 0xADC, 0xADE, 0xADF, 0xAE1, 0xAE2, 0xAE4, 0xAE5, 0xAE7, 0xAE8, 0xAEA,
    0xAEB, 0xAED, 0xAEE, 0xAF0, 0xAF2, 0xAF3, 0xAF5, 0xAF6, 0xAF8, 0xAF9, 0xAFB, 0xAFC, 0xAFE, 0xAFF, 0xB01, 0xB02,
    0xB04, 0xB05, 0xB07, 0xB08, 0xB0A, 0xB0B, 0xB0D, 0xB0E, 0xB10, 0xB11, 0xB13, 0xB14, 0xB16, 0xB17, 0xB19, 0xB1A,
    0xB1C, 0xB1D, 0xB1F, 0xB20, 0xB22, 0xB23, 0xB24, 0xB26, 0xB27, 0xB29, 0xB2A, 0xB2C, 0xB2D, 0xB2F, 0xB30, 0xB32,
    0xB33, 0xB35, 0xB36, 0xB37, 0xB39, 0xB3A, 0xB3C, 0xB3D, 0xB3F, 0xB40, 0xB42, 0xB43, 0xB44, 0xB46, 0xB47, 0xB49,
    0xB4A, 0xB4C, 0xB4D, 0xB4E, 0xB50, 0xB51, 0xB53, 0xB54, 0xB55, 0xB57, 0xB58, 0xB5A, 0xB5B, 0xB5C, 0xB5E, 0xB5F,
    0xB61, 0xB62, 0xB63, 0xB65, 0xB66, 0xB68, 0xB69, 0xB6A, 0xB6C, 0xB6D, 0xB6F, 0xB70, 0xB71, 0xB73, 0xB74, 0xB75,
    0xB77, 0xB78, 0xB7A, 0xB7B, 0xB7C, 0xB7E, 0xB7F, 0xB80, 0xB82, 0xB83, 0xB84, 0xB86, 0xB87, 0xB89, 0xB8A, 0xB8B,
    0xB8D, 0xB8E, 0xB8F, 0xB91, 0xB92, 0xB93, 0xB95, 0xB96, 0xB97, 0xB99, 0xB9A, 0xB9B, 0xB9D, 0xB9E, 0xB9F, 0xBA1,
    0xBA2, 0xBA3, 0xBA5, 0xBA6, 0xBA7, 0xBA8, 0xBAA, 0xBAB, 0xBAC, 0xBAE, 0xBAF, 0xBB0, 0xBB2, 0xBB3, 0xBB4, 0xBB6,
    0xBB7, 0xBB8, 0xBB9, 0xBBB, 0xBBC, 0xBBD, 0xBBF, 0xBC0, 0xBC1, 0xBC2, 0xBC4, 0xBC5, 0xBC6, 0xBC8, 0xBC9, 0xBCA,
    0xBCB, 0xBCD, 0xBCE, 0xBCF, 0xBD0, 0xBD2, 0xBD3, 0xBD4, 0xBD5, 0xBD7, 0xBD8, 0xBD9, 0xBDB, 0xBDC, 0xBDD, 0xBDE,
    0xBE0, 0xBE1, 0xBE2, 0xBE3, 0xBE4, 0xBE6, 0xBE7, 0xBE8, 0xBE9, 0xBEB, 0xBEC, 0xBED, 0xBEE, 0xBF0, 0xBF1, 0xBF2,
    0xBF3, 0xBF5, 0xBF6, 0xBF7, 0xBF8, 0xBF9, 0xBFB, 0xBFC, 0xBFD, 0xBFE, 0xBFF, 0xC01, 0xC02, 0xC03, 0xC04, 0xC05,
    0xC07, 0xC08, 0xC09, 0xC0A, 0xC0B, 0xC0D, 0xC0E, 0xC0F, 0xC10, 0xC11, 0xC13, 0xC14, 0xC15, 0xC16, 0xC17, 0xC19,
    0xC1A, 0xC1B, 0xC1C, 0xC1D, 0xC1E, 0xC20, 0xC21, 0xC22, 0xC23, 0xC24, 0xC25, 0xC27, 0xC28, 0xC29, 0xC2A, 0xC2B,
    0xC2C, 0xC2E, 0xC2F, 0xC30, 0xC31, 0xC32, 0xC33, 0xC34, 0xC36, 0xC37, 0xC38, 0xC39, 0xC3A, 0xC3B, 0xC3C, 0xC3E,
    0xC3F, 0xC40, 0xC41, 0xC42, 0xC43, 0xC44, 0xC46, 0xC47, 0xC48, 0xC49, 0xC4A, 0xC4B, 0xC4C, 0xC4D, 0xC4F, 0xC50,
    0xC51, 0xC52, 0xC53, 0xC54, 0xC55, 0xC56, 0xC57, 0xC59, 0xC5A, 0xC5B, 0xC5C, 0xC5D, 0xC5E, 0xC5F, 0xC60, 0xC61,
    0xC62, 0xC63, 0xC65, 0xC66, 0xC67, 0xC68, 0xC69, 0xC6A, 0xC6B, 0xC6C, 0xC6D, 0xC6E, 0xC6F, 0xC71, 0xC72, 0xC73,
    0xC74, 0xC75, 0xC76, 0xC77, 0xC78, 0xC79, 0xC7A, 0xC7B, 0xC7C, 0xC7D, 0xC7E, 0xC7F, 0xC81, 0xC82, 0xC83, 0xC84,
    0xC85, 0xC86, 0xC87, 0xC88, 0xC89, 0xC8A, 0xC8B, 0xC8C, 0xC8D, 0xC8E, 0xC8F, 0xC90, 0xC91, 0xC92, 0xC93, 0xC94,
    0xC95, 0xC96, 0xC97, 0xC99, 0xC9A, 0xC9B, 0xC9C, 0xC9D, 0xC9E, 0xC9F, 0xCA0, 0xCA1, 0xCA2, 0xCA3, 0xCA4, 0xCA5,
    0xCA6, 0xCA7, 0xCA8, 0xCA9, 0xCAA, 0xCAB, 0xCAC, 0xCAD, 0xCAE, 0xCAF, 0xCB0, 0xCB1, 0xCB2, 0xCB3, 0xCB4, 0xCB5,
    0xCB6, 0xCB7, 0xCB8, 0xCB9, 0xCBA, 0xCBB, 0xCBC, 0xCBD, 0xCBE, 0xCBF, 0xCC0, 0xCC1, 0xCC2, 0xCC3, 0xCC4, 0xCC5,
    0xCC6, 0xCC7, 0xCC8, 0xCC9, 0xCCA, 0xCCA, 0xCCB, 0xCCC, 0xCCD, 0xCCE, 0xCCF, 0xCD0, 0xCD1, 0xCD2, 0xCD3, 0xCD4,
    0xCD5, 0xCD6, 0xCD7, 0xCD8, 0xCD9, 0xCDA, 0xCDB, 0xCDC, 0xCDD, 0xCDE, 0xCDF, 0xCE0, 0xCE0, 0xCE1, 0xCE2, 0xCE3,
    0xCE4, 0xCE5, 0xCE6, 0xCE7, 0xCE8, 0xCE9, 0xCEA, 0xCEB, 0xCEC, 0xCED, 0xCEE, 0xCEF, 0xCEF, 0xCF0, 0xCF1, 0xCF2,
    0xCF3, 0xCF4, 0xCF5, 0xCF6, 0xCF7, 0xCF8, 0xCF9, 0xCFA, 0xCFA, 0xCFB, 0xCFC, 0xCFD, 0xCFE, 0xCFF, 0xD00, 0xD01,
    0xD02, 0xD03, 0xD04, 0xD04, 0xD05, 0xD06, 0xD07, 0xD08, 0xD09, 0xD0A, 0xD0B, 0xD0C, 0xD0D, 0xD0D, 0xD0E, 0xD0F,
    0xD10, 0xD11, 0xD12, 0xD13, 0xD14, 0xD15, 0xD15, 0xD16, 0xD17, 0xD18, 0xD19, 0xD1A, 0xD1B, 0xD1C, 0xD1C, 0xD1D,
    0xD1E, 0xD1F, 0xD20, 0xD21, 0xD22, 0xD23, 0xD23, 0xD24, 0xD25, 0xD26, 0xD27, 0xD28, 0xD29, 0xD29, 0xD2A, 0xD2B,
    0xD2C, 0xD2D, 0xD2E, 0xD2F, 0xD2F, 0xD30, 0xD31, 0xD32, 0xD33, 0xD34, 0xD34, 0xD35, 0xD36, 0xD37, 0xD38, 0xD39,
    0xD3A, 0xD3A, 0xD3B, 0xD3C, 0xD3D, 0xD3E, 0xD3F, 0xD3F, 0xD40, 0xD41, 0xD42, 0xD43, 0xD44, 0xD44, 0xD45, 0xD46,
    0xD47, 0xD48, 0xD48, 0xD49, 0xD4A, 0xD4B, 0xD4C, 0xD4D, 0xD4D, 0xD4E, 0xD4F, 0xD50, 0xD51, 0xD51, 0xD52, 0xD53,
    0xD54, 0xD55, 0xD55, 0xD56, 0xD57, 0xD58, 0xD59, 0xD5A, 0xD5A, 0xD5B, 0xD5C, 0xD5D, 0xD5D, 0xD5E, 0xD5F, 0xD60,
    0xD61, 0xD61, 0xD62, 0xD63, 0xD64, 0xD65, 0xD65, 0xD66, 0xD67, 0xD68, 0xD69, 0xD69, 0xD6A, 0xD6B, 0xD6C, 0xD6C,
    0xD6D, 0xD6E, 0xD6F, 0xD70, 0xD70, 0xD71, 0xD72, 0xD73, 0xD73, 0xD74, 0xD75, 0xD76, 0xD77, 0xD77, 0xD78, 0xD79,
    0xD7A, 0xD7A, 0xD7B, 0xD7C, 0xD7D, 0xD7D, 0xD7E, 0xD7F, 0xD80, 0xD80, 0xD81, 0xD82, 0xD83, 0xD83, 0xD84, 0xD85,
    0xD86, 0xD86, 0xD87, 0xD88, 0xD89, 0xD89, 0xD8A, 0xD8B, 0xD8C, 0xD8C, 0xD8D, 0xD8E, 0xD8F, 0xD8F, 0xD90, 0xD91,
    0xD92, 0xD92, 0xD93, 0xD94, 0xD94, 0xD95, 0xD96, 0xD97, 0xD97, 0xD98, 0xD99, 0xD9A, 0xD9A, 0xD9B, 0xD9C, 0xD9C,
    0xD9D, 0xD9E, 0xD9F, 0xD9F, 0xDA0, 0xDA1, 0xDA1, 0xDA2, 0xDA3, 0xDA4, 0xDA4, 0xDA5, 0xDA6, 0xDA6, 0xDA7, 0xDA8,
    0xDA9, 0xDA9, 0xDAA, 0xDAB, 0xDAB, 0xDAC, 0xDAD, 0xDAE, 0xDAE, 0xDAF, 0xDB0, 0xDB0, 0xDB1, 0xDB2, 0xDB2, 0xDB3,
    0xDB4, 0xDB5, 0xDB5, 0xDB6, 0xDB7, 0xDB7, 0xDB8, 0xDB9, 0xDB9, 0xDBA, 0xDBB, 0xDBB, 0xDBC, 0xDBD, 0xDBD, 0xDBE,
    0xDBF, 0xDC0, 0xDC0, 0xDC1, 0xDC2, 0xDC2, 0xDC3, 0xDC4, 0xDC4, 0xDC5, 0xDC6, 0xDC6, 0xDC7, 0xDC8, 0xDC8, 0xDC9,
    0xDCA, 0xDCA, 0xDCB, 0xDCC, 0xDCC, 0xDCD, 0xDCE, 0xDCE, 0xDCF, 0xDD0, 0xDD0, 0xDD1, 0xDD2, 0xDD2, 0xDD3, 0xDD4,
    0xDD4, 0xDD5, 0xDD6, 0xDD6, 0xDD7, 0xDD8, 0xDD8, 0xDD9, 0xDD9, 0xDDA, 0xDDB, 0xDDB, 0xDDC, 0xDDD, 0xDDD, 0xDDE,
    0xDDF, 0xDDF, 0xDE0, 0xDE1, 0xDE1, 0xDE2, 0xDE2, 0xDE3, 0xDE4, 0xDE4, 0xDE5, 0xDE6, 0xDE6, 0xDE7, 0xDE8, 0xDE8,
    0xDE9, 0xDE9, 0xDEA, 0xDEB, 0xDEB, 0xDEC, 0xDED, 0xDED, 0xDEE, 0xDEE, 0xDEF, 0xDF0, 0xDF0, 0xDF1, 0xDF2, 0xDF2,
    0xDF3, 0xDF3, 0xDF4, 0xDF5, 0xDF5, 0xDF6, 0xDF7, 0xDF7, 0xDF8, 0xDF8, 0xDF9, 0xDFA, 0xDFA, 0xDFB, 0xDFB, 0xDFC,
    0xDFD, 0xDFD, 0xDFE, 0xDFE, 0xDFF, 0xE00, 0xE00, 0xE01, 0xE02, 0xE02, 0xE03, 0xE03, 0xE04, 0xE05, 0xE05, 0xE06,
    0xE06, 0xE07, 0xE08, 0xE08, 0xE09, 0xE09, 0xE0A, 0xE0A, 0xE0B, 0xE0C, 0xE0C, 0xE0D, 0xE0D, 0xE0E, 0xE0F, 0xE0F,
    0xE10, 0xE10, 0xE11, 0xE12, 0xE12, 0xE13, 0xE13, 0xE14, 0xE14, 0xE15, 0xE16, 0xE16, 0xE17, 0xE17, 0xE18, 0xE18,
    0xE19, 0xE1A, 0xE1A, 0xE1B, 0xE1B, 0xE1C, 0xE1C, 0xE1D, 0xE1E, 0xE1E, 0xE1F, 0xE1F, 0xE20, 0xE20, 0xE21, 0xE22,
    0xE22, 0xE23, 0xE23, 0xE24, 0xE24, 0xE25, 0xE26, 0xE26, 0xE27, 0xE27, 0xE28, 0xE28, 0xE29, 0xE29, 0xE2A, 0xE2B,
    0xE2B, 0xE2C, 0xE2C, 0xE2D, 0xE2D, 0xE2E, 0xE2E, 0xE2F, 0xE30, 0xE30, 0xE31, 0xE31, 0xE32, 0xE32, 0xE33, 0xE33,
    0xE34, 0xE34, 0xE35, 0xE36, 0xE36, 0xE37, 0xE37, 0xE38, 0xE38, 0xE39, 0xE39, 0xE3A, 0xE3A, 0xE3B, 0xE3B, 0xE3C,
    0xE3C, 0xE3D, 0xE3E, 0xE3E, 0xE3F, 0xE3F, 0xE40, 0xE40, 0xE41, 0xE41, 0xE42, 0xE42, 0xE43, 0xE43, 0xE44, 0xE44};
