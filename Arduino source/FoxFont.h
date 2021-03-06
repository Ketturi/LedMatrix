/*
  10 pixels high variable width font for LED matrix display
  created by
  Ketturi Fox 2017

  This work is licensed under a Creative Commons Attribution-ShareAlike 4.0 International License.
  https://creativecommons.org/licenses/by-sa/4.0/
*/

const uint8_t FoxFontBitmaps[] PROGMEM = {
  // Bitmap Data:

  /* 0x20 032 */
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, /* 0x21 033 */
  0x90, 0x90, 0x90, /* 0x22 034 */
  0x48, 0x48, 0xFC, 0x48, 0x48, 0xFC, 0x48, 0x48, /* 0x23 035 */
  0x20, 0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, 0x20, /* 0x24 036 */
  0x42, 0xA4, 0x48, 0x10, 0x24, 0x4A, 0x84, /* 0x25 037 */
  0x30, 0x48, 0x30, 0x4C, 0x88, 0x88, 0x74, /* 0x26 038 */
  0x40, 0x40, 0x80, /* 0x27 039 */
  0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x20, /* 0x28 040 */
  0x80, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x80, /* 0x29 041 */
  0xA8, 0x70, 0xF8, 0x70, 0xA8, /* 0x2A 042 */
  0x20, 0x20, 0xF8, 0x20, 0x20, /* 0x2B 043 */
  0x40, 0x80, /* 0x2C 044 */
  0xF8, /* 0x2D 045 */
  0x80, /* 0x2E 046 */
  0x04, 0x08, 0x10, 0x20, 0x40, 0x80, /* 0x2F 047 */
  0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0x30 048 */
  0x40, 0xC0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0x31 049 */
  0x70, 0x88, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, /* 0x32 050 */
  0x70, 0x88, 0x08, 0x30, 0x08, 0x08, 0x88, 0x70, /* 0x33 051 */
  0x08, 0x18, 0x28, 0x48, 0x88, 0xF8, 0x08, 0x08, /* 0x34 052 */
  0xF8, 0x80, 0x80, 0xF0, 0x08, 0x08, 0x88, 0x70, /* 0x35 053 */
  0x70, 0x88, 0x80, 0xF0, 0x88, 0x88, 0x88, 0x70, /* 0x36 054 */
  0xF8, 0x08, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, /* 0x37 055 */
  0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x88, 0x70, /* 0x38 056 */
  0x70, 0x88, 0x88, 0x88, 0x78, 0x08, 0x88, 0x70, /* 0x39 057 */
  0x80, 0x00, 0x00, 0x00, 0x00, 0x80, /* 0x3A 058 */
  0x40, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, /* 0x3B 059 */
  0x10, 0x20, 0x40, 0x80, 0x40, 0x20, 0x10, /* 0x3C 060 */
  0xF8, 0x00, 0xF8, /* 0x3D 061 */
  0x80, 0x40, 0x20, 0x10, 0x20, 0x40, 0x80, /* 0x3E 062 */
  0x70, 0x88, 0x08, 0x10, 0x20, 0x20, 0x00, 0x20, /* 0x3F 063 */
  0x7C, 0x82, 0xBA, 0xAA, 0xAA, 0xBC, 0x80, 0x7E, /* 0x40 064 */
  0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, /* 0x41 065 */
  0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0x88, 0xF0, /* 0x42 066 */
  0x70, 0x88, 0x80, 0x80, 0x80, 0x80, 0x88, 0x70, /* 0x43 067 */
  0xE0, 0x90, 0x88, 0x88, 0x88, 0x88, 0x90, 0xE0, /* 0x44 068 */
  0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0x80, 0xF8, /* 0x45 069 */
  0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0x80, 0x80, /* 0x46 070 */
  0x70, 0x88, 0x80, 0x80, 0x98, 0x88, 0x88, 0x70, /* 0x47 071 */
  0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, 0x88, /* 0x48 072 */
  0xE0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0x49 073 */
  0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60, /* 0x4A 074 */
  0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88, 0x88, /* 0x4B 075 */
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xF8, /* 0x4C 076 */
  0x82, 0xC6, 0xAA, 0x92, 0x82, 0x82, 0x82, 0x82, /* 0x4D 077 */
  0x84, 0xC4, 0xA4, 0x94, 0x8C, 0x84, 0x84, 0x84, /* 0x4E 078 */
  0x78, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x78, /* 0x4F 079 */
  0xF0, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x80, 0x80, /* 0x50 080 */
  0x78, 0x84, 0x84, 0x84, 0x84, 0xA4, 0x94, 0x78, 0x08, /* 0x51 081 */
  0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0x88, 0x88, /* 0x52 082 */
  0x70, 0x88, 0x80, 0x70, 0x08, 0x08, 0x88, 0x70, /* 0x53 083 */
  0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, /* 0x54 084 */
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0x55 085 */
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x50, 0x20, /* 0x56 086 */
  0x82, 0x82, 0x82, 0x92, 0x92, 0xAA, 0xAA, 0x44, /* 0x57 087 */
  0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x88, /* 0x58 088 */
  0x88, 0x88, 0x50, 0x50, 0x20, 0x20, 0x20, 0x20, /* 0x59 089 */
  0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0xF8, /* 0x5A 090 */
  0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, /* 0x5B 091 */
  0x80, 0x40, 0x20, 0x10, 0x08, 0x04, /* 0x5C 092 */
  0xE0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xE0, /* 0x5D 093 */
  0x20, 0x50, 0x88, /* 0x5E 094 */
  0xF8, /* 0x5F 095 */
  0x80, 0x40, 0x20, /* 0x60 096 */
  0x70, 0x08, 0x78, 0x88, 0x98, 0x68, /* 0x61 097 */
  0x80, 0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0xF0, /* 0x62 098 */
  0x70, 0x88, 0x80, 0x80, 0x88, 0x70, /* 0x63 099 */
  0x08, 0x08, 0x08, 0x68, 0x98, 0x88, 0x88, 0x78, /* 0x64 100 */
  0x70, 0x88, 0xF0, 0x80, 0x88, 0x70, /* 0x65 101 */
  0x30, 0x40, 0x40, 0xF0, 0x40, 0x40, 0x40, 0x40, /* 0x66 102 */
  0x78, 0x88, 0x88, 0x98, 0x68, 0x08, 0x70, /* 0x67 103 */
  0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0x88, 0x88, /* 0x68 104 */
  0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, /* 0x69 105 */
  0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0xC0, /* 0x6A 106 */
  0x80, 0x80, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x90, /* 0x6B 107 */
  0xC0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x30, /* 0x6C 108 */
  0xEC, 0x92, 0x92, 0x92, 0x92, 0x92, /* 0x6D 109 */
  0xB0, 0xC8, 0x88, 0x88, 0x88, 0x88, /* 0x6E 110 */
  0x70, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0x6F 111 */
  0xB0, 0xC8, 0x88, 0x88, 0xF0, 0x80, 0x80, /* 0x70 112 */
  0x78, 0x88, 0x88, 0x98, 0x68, 0x08, 0x08, /* 0x71 113 */
  0xB0, 0xC8, 0x80, 0x80, 0x80, 0x80, /* 0x72 114 */
  0x70, 0x88, 0x70, 0x08, 0x88, 0x70, /* 0x73 115 */
  0x40, 0x40, 0xF0, 0x40, 0x40, 0x40, 0x40, 0x30, /* 0x74 116 */
  0x88, 0x88, 0x88, 0x88, 0x98, 0x68, /* 0x75 117 */
  0x88, 0x88, 0x88, 0x88, 0x50, 0x20, /* 0x76 118 */
  0x82, 0x82, 0x82, 0x92, 0xAA, 0x44, /* 0x77 119 */
  0x88, 0x50, 0x20, 0x20, 0x50, 0x88, /* 0x78 120 */
  0x88, 0x88, 0x98, 0x68, 0x08, 0x88, 0x70, /* 0x79 121 */
  0xF8, 0x08, 0x30, 0x40, 0x80, 0xF8, /* 0x7A 122 */
  0x30, 0x40, 0x40, 0x40, 0x80, 0x40, 0x40, 0x40, 0x40, 0x30, /* 0x7B 123 */
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, /* 0x7C 124 */
  0xC0, 0x20, 0x20, 0x20, 0x10, 0x20, 0x20, 0x20, 0x20, 0xC0, /* 0x7D 125 */
  0x48, 0xA8, 0x90, /* 0x7E 126 */
  0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, /* 0x7F 127 */
  0x38, 0x44, 0x40, 0xF0, 0x40, 0xF0, 0x40, 0x44, 0x38, /* 0x80 128 */
  0xFC, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xFC, /* 0x81 129 */
  0xC0, 0xC0, 0x40, 0x80, /* 0x82 130 */
  0x18, 0x20, 0x20, 0x70, 0x20, 0x20, 0x20, 0xC0, /* 0x83 131 */
  0xD8, 0xD8, 0x48, 0x90, /* 0x84 132 */
  0xA8, /* 0x85 133 */
  0x40, 0xE0, 0x40, 0x40, /* 0x86 134 */
  0x40, 0xE0, 0x40, 0xE0, 0x40, 0x40, 0x40, /* 0x87 135 */
  0x40, 0xA0, /* 0x88 136 */
  0x42, 0xA4, 0x48, 0x10, 0x20, 0x54, 0xAA, 0x14, /* 0x89 137 */
  0x44, 0x28, 0x78, 0x84, 0x80, 0x78, 0x04, 0x84, 0x78, /* 0x8A 138 */
  0x40, 0x80, 0x40, /* 0x8B 139 */
  0x7C, 0x90, 0x90, 0x90, 0x9C, 0x90, 0x90, 0x7C, /* 0x8C 140 */
  0xFC, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xFC, /* 0x8D 141 */
  0x88, 0x50, 0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, /* 0x8E 142 */
  0xFC, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xFC, /* 0x8F 143 */
  0xFC, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xFC, /* 0x90 144 */
  0xC0, 0xC0, 0x80, 0x40, /* 0x91 145 */
  0xC0, 0xC0, 0x40, 0x80, /* 0x92 146 */
  0x48, 0x90, 0xD8, 0xD8, /* 0x93 147 */
  0xD8, 0xD8, 0x48, 0x90, /* 0x94 148 */
  0x20, 0x70, 0xF8, 0x70, 0x20, /* 0x95 149 */
  0xE0, /* 0x96 150 */
  0xF8, /* 0x97 151 */
  0x50, 0xA0, /* 0x98 152 */
  0xEE, 0x4E, 0x4A, 0x4A, /* 0x99 153 */
  0x50, 0x20, 0x78, 0x84, 0x70, 0x08, 0x84, 0x78, /* 0x9A 154 */
  0x80, 0x40, 0x80, /* 0x9B 155 */
  0x78, 0xA4, 0xB8, 0xA0, 0xA4, 0x78, /* 0x9C 156 */
  0xFC, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xFC, /* 0x9D 157 */
  0x28, 0x10, 0x00, 0xFC, 0x08, 0x10, 0x20, 0x40, 0xFC, /* 0x9E 158 */
  0x28, 0x82, 0x82, 0x44, 0x38, 0x10, 0x10, 0x10, 0x10, /* 0x9F 159 */
  /* 0xA0 160 */
  0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, /* 0xA1 161 */
  0x20, 0x70, 0xA8, 0xA0, 0xA0, 0xA8, 0x70, 0x20, /* 0xA2 162 */
  0x30, 0x48, 0x40, 0xF8, 0x40, 0x40, 0x64, 0xD8, /* 0xA3 163 */
  0x88, 0x70, 0x88, 0x88, 0x70, 0x88, /* 0xA4 164 */
  0x88, 0x50, 0x20, 0xF8, 0x20, 0xF8, 0x20, /* 0xA5 165 */
  0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, /* 0xA6 166 */
  0x60, 0x90, 0x80, 0xE0, 0x90, 0x70, 0x10, 0x90, 0x60, /* 0xA7 167 */
  0x90, /* 0xA8 168 */
  0x3C, 0x42, 0x99, 0xA1, 0xA1, 0x99, 0x42, 0x3C, /* 0xA9 169 */
  0x70, 0x08, 0x78, 0x88, 0x78, 0x00, 0xF8, /* 0xAA 170 */
  0x12, 0x24, 0x48, 0x90, 0x48, 0x24, 0x12, /* 0xAB 171 */
  0xF8, 0x08, 0x08, 0x08, /* 0xAC 172 */
  0xF0, /* 0xAD 173 */
  0x3C, 0x42, 0xB9, 0xA5, 0xB9, 0xA5, 0x42, 0x3C, /* 0xAE 174 */
  0xFC, /* 0xAF 175 */
  0x60, 0x90, 0x90, 0x60, /* 0xB0 176 */
  0x20, 0x20, 0xF8, 0x20, 0x20, 0x00, 0xF8, /* 0xB1 177 */
  0xE0, 0x20, 0xE0, 0x80, 0xE0, /* 0xB2 178 */
  0xE0, 0x20, 0xE0, 0x20, 0xE0, /* 0xB3 179 */
  0x40, 0x80, /* 0xB4 180 */
  0x90, 0x90, 0x90, 0xB0, 0xD8, 0x80, 0x80, /* 0xB5 181 */
  0x78, 0xE8, 0xE8, 0x78, 0x28, 0x28, 0x28, 0x28, /* 0xB6 182 */
  0x80, /* 0xB7 183 */
  0x40, 0x20, 0xC0, /* 0xB8 184 */
  0x40, 0xC0, 0x40, 0x40, 0xE0, /* 0xB9 185 */
  0x60, 0x90, 0x90, 0x60, 0x00, 0xF0, /* 0xBA 186 */
  0x90, 0x48, 0x24, 0x12, 0x24, 0x48, 0x90, /* 0xBB 187 */
  0x42, 0x44, 0x48, 0x50, 0x2A, 0x4A, 0x8E, 0x02, 0x02, /* 0xBC 188 */
  0x42, 0x44, 0x48, 0x50, 0x2E, 0x42, 0x8E, 0x08, 0x0E, /* 0xBD 189 */
  0xC0, 0x22, 0x64, 0x28, 0xD0, 0x2A, 0x4A, 0x8E, 0x02, 0x02, /* 0xBE 190 */
  0x20, 0x00, 0x20, 0x20, 0x10, 0x08, 0x88, 0x70, /* 0xBF 191 */
  0x40, 0x20, 0x00, 0x20, 0x50, 0x88, 0xF8, 0x88, 0x88, /* 0xC0 192 */
  0x10, 0x20, 0x00, 0x20, 0x50, 0x88, 0xF8, 0x88, 0x88, /* 0xC1 193 */
  0x20, 0x50, 0x00, 0x20, 0x50, 0x88, 0xF8, 0x88, 0x88, /* 0xC2 194 */
  0x28, 0x50, 0x00, 0x20, 0x50, 0x88, 0xF8, 0x88, 0x88, /* 0xC3 195 */
  0x50, 0x00, 0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, /* 0xC4 196 */
  0x20, 0x00, 0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, /* 0xC5 197 */
  0x7C, 0x90, 0x90, 0x90, 0xFC, 0x90, 0x90, 0x9C, /* 0xC6 198 */
  0x78, 0x84, 0x80, 0x80, 0x80, 0x84, 0x78, 0x10, 0x30, /* 0xC7 199 */
  0x40, 0x20, 0x00, 0xF8, 0x80, 0xF0, 0x80, 0x80, 0xF8, /* 0xC8 200 */
  0x10, 0x20, 0x00, 0xF8, 0x80, 0xF0, 0x80, 0x80, 0xF8, /* 0xC9 201 */
  0x20, 0x50, 0x00, 0xF8, 0x80, 0xF0, 0x80, 0x80, 0xF8, /* 0xCA 202 */
  0x50, 0x00, 0xF8, 0x80, 0x80, 0xF0, 0x80, 0x80, 0xF8, /* 0xCB 203 */
  0x80, 0x40, 0x00, 0xE0, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0xCC 204 */
  0x20, 0x40, 0x00, 0xE0, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0xCD 205 */
  0x40, 0xA0, 0x00, 0xE0, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0xCE 206 */
  0xA0, 0x00, 0xE0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0xCF 207 */
  0xF0, 0x88, 0x84, 0xE4, 0x84, 0x84, 0x88, 0xF0, /* 0xD0 208 */
  0x28, 0x50, 0x00, 0x84, 0xC4, 0xA4, 0x94, 0x8C, 0x84, /* 0xD1 209 */
  0x20, 0x10, 0x00, 0x78, 0x84, 0x84, 0x84, 0x84, 0x78, /* 0xD2 210 */
  0x10, 0x20, 0x00, 0x78, 0x84, 0x84, 0x84, 0x84, 0x78, /* 0xD3 211 */
  0x30, 0x48, 0x00, 0x78, 0x84, 0x84, 0x84, 0x84, 0x78, /* 0xD4 212 */
  0x28, 0x50, 0x00, 0x78, 0x84, 0x84, 0x84, 0x84, 0x78, /* 0xD5 213 */
  0x48, 0x00, 0x78, 0x84, 0x84, 0x84, 0x84, 0x84, 0x78, /* 0xD6 214 */
  0x88, 0x50, 0x20, 0x50, 0x88, /* 0xD7 215 */
  0x78, 0x8C, 0x94, 0x94, 0xA4, 0xA4, 0xC4, 0x78, /* 0xD8 216 */
  0x40, 0x20, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xD9 217 */
  0x10, 0x20, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xDA 218 */
  0x20, 0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xDB 219 */
  0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xDC 220 */
  0x10, 0x20, 0x88, 0x88, 0x50, 0x50, 0x20, 0x20, 0x20, /* 0xDD 221 */
  0x80, 0xF0, 0x88, 0x88, 0x88, 0xF0, 0x80, /* 0xDE 222 */
  0x30, 0x48, 0x88, 0xB0, 0x88, 0x88, 0x88, 0xB0, /* 0xDF 223 */
  0x40, 0x20, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78, /* 0xE0 224 */
  0x10, 0x20, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78, /* 0xE1 225 */
  0x20, 0x50, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78, /* 0xE2 226 */
  0x28, 0x50, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78, /* 0xE3 227 */
  0x50, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78, /* 0xE4 228 */
  0x20, 0x00, 0x70, 0x08, 0x78, 0x88, 0x88, 0x78, /* 0xE5 229 */
  0x7C, 0x12, 0x7E, 0x90, 0x90, 0x7E, /* 0xE6 230 */
  0x78, 0x84, 0x80, 0x80, 0x84, 0x78, 0x10, 0x30, /* 0xE7 231 */
  0x40, 0x20, 0x00, 0x70, 0x88, 0xF0, 0x80, 0x88, 0x70, /* 0xE8 232 */
  0x10, 0x20, 0x00, 0x70, 0x88, 0xF0, 0x80, 0x88, 0x70, /* 0xE9 233 */
  0x20, 0x50, 0x00, 0x70, 0x88, 0xF0, 0x80, 0x88, 0x70, /* 0xEA 234 */
  0x50, 0x00, 0x70, 0x88, 0xF0, 0x80, 0x88, 0x70, /* 0xEB 235 */
  0x80, 0x40, 0x00, 0xC0, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0xEC 236 */
  0x20, 0x40, 0x00, 0xC0, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0xED 237 */
  0x40, 0xA0, 0x00, 0xC0, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0xEE 238 */
  0xA0, 0x00, 0xC0, 0x40, 0x40, 0x40, 0x40, 0xE0, /* 0xEF 239 */
  0x28, 0x10, 0x28, 0x04, 0x7E, 0x82, 0x82, 0x82, 0x7C, /* 0xF0 240 */
  0x28, 0x50, 0x00, 0xB0, 0xC8, 0x88, 0x88, 0x88, 0x88, /* 0xF1 241 */
  0x40, 0x20, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xF2 242 */
  0x10, 0x20, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xF3 243 */
  0x20, 0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xF4 244 */
  0x28, 0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xF5 245 */
  0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x70, /* 0xF6 246 */
  0x20, 0x00, 0xF8, 0x00, 0x20, /* 0xF7 247 */
  0x78, 0x8C, 0x94, 0xA4, 0xC4, 0x78, /* 0xF8 248 */
  0x40, 0x20, 0x00, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, /* 0xF9 249 */
  0x10, 0x20, 0x00, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, /* 0xFA 250 */
  0x20, 0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, /* 0xFB 251 */
  0x50, 0x00, 0x88, 0x88, 0x88, 0x88, 0x98, 0x68, /* 0xFC 252 */
  0x10, 0x20, 0x00, 0x88, 0x88, 0x98, 0x68, 0x08, 0x88, 0x70, /* 0xFD 253 */
  0x80, 0x80, 0xF0, 0x88, 0x88, 0x88, 0xF0, 0x80, 0x80, /* 0xFE 254 */
  0x50, 0x00, 0x88, 0x88, 0x98, 0x68, 0x08, 0x88, 0x70 /* 0xFF 255 */
};

const GFXglyph FoxFontGlyphs[] PROGMEM = {
  // bitmapOffset, width, height, xAdvance, xOffset, yOffset
  { 0, 0, 0, 3, 0, 1 },  /* 0x20 032 */ //SPACE, Special, do not replace from converter
  { 0, 8, 8, 2, 0, -8 }, /* 0x21 033 */
  { 8, 8, 3, 5, 0, -9 }, /* 0x22 034 */
  { 11, 8, 8, 7, 0, -8 }, /* 0x23 035 */
  { 19, 8, 9, 6, 0, -9 }, /* 0x24 036 */
  { 28, 8, 7, 8, 0, -8 }, /* 0x25 037 */
  { 35, 8, 7, 7, 0, -8 }, /* 0x26 038 */
  { 42, 8, 3, 3, 0, -9 }, /* 0x27 039 */
  { 45, 8, 10, 4, 0, -9 }, /* 0x28 040 */
  { 55, 8, 10, 4, 0, -9 }, /* 0x29 041 */
  { 65, 8, 5, 6, 0, -7 }, /* 0x2A 042 */
  { 70, 8, 5, 6, 0, -7 }, /* 0x2B 043 */
  { 75, 8, 2, 3, 0, -1 }, /* 0x2C 044 */
  { 77, 8, 1, 6, 0, -5 }, /* 0x2D 045 */
  { 78, 8, 1, 2, 0, -1 }, /* 0x2E 046 */
  { 79, 8, 6, 7, 0, -7 }, /* 0x2F 047 */
  { 85, 8, 8, 6, 0, -8 }, /* 0x30 048 */
  { 93, 8, 8, 4, 0, -8 }, /* 0x31 049 */
  { 101, 8, 8, 6, 0, -8 }, /* 0x32 050 */
  { 109, 8, 8, 6, 0, -8 }, /* 0x33 051 */
  { 117, 8, 8, 6, 0, -8 }, /* 0x34 052 */
  { 125, 8, 8, 6, 0, -8 }, /* 0x35 053 */
  { 133, 8, 8, 6, 0, -8 }, /* 0x36 054 */
  { 141, 8, 8, 6, 0, -8 }, /* 0x37 055 */
  { 149, 8, 8, 6, 0, -8 }, /* 0x38 056 */
  { 157, 8, 8, 6, 0, -8 }, /* 0x39 057 */
  { 165, 8, 6, 2, 0, -6 }, /* 0x3A 058 */
  { 171, 8, 7, 3, 0, -6 }, /* 0x3B 059 */
  { 178, 8, 7, 5, 0, -8 }, /* 0x3C 060 */
  { 185, 8, 3, 6, 0, -6 }, /* 0x3D 061 */
  { 188, 8, 7, 5, 0, -8 }, /* 0x3E 062 */
  { 195, 8, 8, 6, 0, -8 }, /* 0x3F 063 */
  { 203, 8, 8, 8, 0, -8 }, /* 0x40 064 */
  { 211, 8, 8, 6, 0, -8 }, /* 0x41 065 */
  { 219, 8, 8, 6, 0, -8 }, /* 0x42 066 */
  { 227, 8, 8, 6, 0, -8 }, /* 0x43 067 */
  { 235, 8, 8, 6, 0, -8 }, /* 0x44 068 */
  { 243, 8, 8, 6, 0, -8 }, /* 0x45 069 */
  { 251, 8, 8, 6, 0, -8 }, /* 0x46 070 */
  { 259, 8, 8, 6, 0, -8 }, /* 0x47 071 */
  { 267, 8, 8, 6, 0, -8 }, /* 0x48 072 */
  { 275, 8, 8, 4, 0, -8 }, /* 0x49 073 */
  { 283, 8, 8, 5, 0, -8 }, /* 0x4A 074 */
  { 291, 8, 8, 6, 0, -8 }, /* 0x4B 075 */
  { 299, 8, 8, 6, 0, -8 }, /* 0x4C 076 */
  { 307, 8, 8, 8, 0, -8 }, /* 0x4D 077 */
  { 315, 8, 8, 7, 0, -8 }, /* 0x4E 078 */
  { 323, 8, 8, 7, 0, -8 }, /* 0x4F 079 */
  { 331, 8, 8, 6, 0, -8 }, /* 0x50 080 */
  { 339, 8, 9, 7, 0, -8 }, /* 0x51 081 */
  { 348, 8, 8, 6, 0, -8 }, /* 0x52 082 */
  { 356, 8, 8, 6, 0, -8 }, /* 0x53 083 */
  { 364, 8, 8, 6, 0, -8 }, /* 0x54 084 */
  { 372, 8, 8, 6, 0, -8 }, /* 0x55 085 */
  { 380, 8, 8, 6, 0, -8 }, /* 0x56 086 */
  { 388, 8, 8, 8, 0, -8 }, /* 0x57 087 */
  { 396, 8, 8, 6, 0, -8 }, /* 0x58 088 */
  { 404, 8, 8, 6, 0, -8 }, /* 0x59 089 */
  { 412, 8, 8, 6, 0, -8 }, /* 0x5A 090 */
  { 420, 8, 10, 4, 0, -9 }, /* 0x5B 091 */
  { 430, 8, 6, 7, 0, -7 }, /* 0x5C 092 */
  { 436, 8, 10, 4, 0, -9 }, /* 0x5D 093 */
  { 446, 8, 3, 6, 0, -9 }, /* 0x5E 094 */
  { 449, 8, 1, 6, 0, 0 }, /* 0x5F 095 */
  { 450, 8, 3, 4, 0, -9 }, /* 0x60 096 */
  { 453, 8, 6, 6, 0, -6 }, /* 0x61 097 */
  { 459, 8, 8, 6, 0, -8 }, /* 0x62 098 */
  { 467, 8, 6, 6, 0, -6 }, /* 0x63 099 */
  { 473, 8, 8, 6, 0, -8 }, /* 0x64 100 */
  { 481, 8, 6, 6, 0, -6 }, /* 0x65 101 */
  { 487, 8, 8, 5, 0, -8 }, /* 0x66 102 */
  { 495, 8, 7, 6, 0, -6 }, /* 0x67 103 */
  { 502, 8, 8, 6, 0, -8 }, /* 0x68 104 */
  { 510, 8, 8, 2, 0, -8 }, /* 0x69 105 */
  { 518, 8, 9, 4, 0, -8 }, /* 0x6A 106 */
  { 527, 8, 8, 5, 0, -8 }, /* 0x6B 107 */
  { 535, 8, 7, 5, 0, -7 }, /* 0x6C 108 */
  { 542, 8, 6, 8, 0, -6 }, /* 0x6D 109 */
  { 548, 8, 6, 6, 0, -6 }, /* 0x6E 110 */
  { 554, 8, 6, 6, 0, -6 }, /* 0x6F 111 */
  { 560, 8, 7, 6, 0, -6 }, /* 0x70 112 */
  { 567, 8, 7, 6, 0, -6 }, /* 0x71 113 */
  { 574, 8, 6, 6, 0, -6 }, /* 0x72 114 */
  { 580, 8, 6, 6, 0, -6 }, /* 0x73 115 */
  { 586, 8, 8, 5, 0, -8 }, /* 0x74 116 */
  { 594, 8, 6, 6, 0, -6 }, /* 0x75 117 */
  { 600, 8, 6, 6, 0, -6 }, /* 0x76 118 */
  { 606, 8, 6, 8, 0, -6 }, /* 0x77 119 */
  { 612, 8, 6, 6, 0, -6 }, /* 0x78 120 */
  { 618, 8, 7, 6, 0, -6 }, /* 0x79 121 */
  { 625, 8, 6, 6, 0, -6 }, /* 0x7A 122 */
  { 631, 8, 10, 5, 0, -9 }, /* 0x7B 123 */
  { 641, 8, 10, 2, 0, -9 }, /* 0x7C 124 */
  { 651, 8, 10, 5, 0, -9 }, /* 0x7D 125 */
  { 661, 8, 3, 6, 0, -9 }, /* 0x7E 126 */
  { 664, 8, 10, 8, 0, -9 }, /* 0x7F 127 */
  { 674, 8, 9, 7, 0, -9 }, /* 0x80 128 */
  { 683, 8, 8, 7, 0, -8 }, /* 0x81 129 */
  { 691, 8, 4, 3, 0, -3 }, /* 0x82 130 */
  { 695, 8, 8, 6, 0, -8 }, /* 0x83 131 */
  { 703, 8, 4, 6, 0, -3 }, /* 0x84 132 */
  { 707, 8, 1, 6, 0, -1 }, /* 0x85 133 */
  { 708, 8, 4, 4, 0, -8 }, /* 0x86 134 */
  { 712, 8, 7, 4, 0, -8 }, /* 0x87 135 */
  { 719, 8, 2, 4, 0, -9 }, /* 0x88 136 */
  { 721, 8, 8, 8, 0, -8 }, /* 0x89 137 */
  { 729, 8, 9, 7, 0, -8 }, /* 0x8A 138 */
  { 738, 8, 3, 3, 0, -8 }, /* 0x8B 139 */
  { 741, 8, 8, 7, 0, -8 }, /* 0x8C 140 */
  { 749, 8, 8, 7, 0, -8 }, /* 0x8D 141 */
  { 757, 8, 9, 6, 0, -9 }, /* 0x8E 142 */
  { 766, 8, 8, 7, 0, -8 }, /* 0x8F 143 */
  { 774, 8, 8, 7, 0, -8 }, /* 0x90 144 */
  { 782, 8, 4, 3, 0, -9 }, /* 0x91 145 */
  { 786, 8, 4, 3, 0, -9 }, /* 0x92 146 */
  { 790, 8, 4, 6, 0, -9 }, /* 0x93 147 */
  { 794, 8, 4, 6, 0, -9 }, /* 0x94 148 */
  { 798, 8, 5, 6, 0, -6 }, /* 0x95 149 */
  { 803, 8, 1, 4, 0, -4 }, /* 0x96 150 */
  { 804, 8, 1, 6, 0, -4 }, /* 0x97 151 */
  { 805, 8, 2, 5, 0, -8 }, /* 0x98 152 */
  { 807, 8, 4, 8, 0, -8 }, /* 0x99 153 */
  { 811, 8, 8, 7, 0, -8 }, /* 0x9A 154 */
  { 819, 8, 3, 3, 0, -8 }, /* 0x9B 155 */
  { 822, 8, 6, 7, 0, -6 }, /* 0x9C 156 */
  { 828, 8, 8, 7, 0, -8 }, /* 0x9D 157 */
  { 836, 8, 9, 7, 0, -9 }, /* 0x9E 158 */
  { 845, 8, 9, 8, 0, -9 }, /* 0x9F 159 */
  { 854, 8, 0, 1, 0, 0 }, /* 0xA0 160 */
  { 854, 8, 8, 2, 0, -8 }, /* 0xA1 161 */
  { 862, 8, 8, 6, 0, -8 }, /* 0xA2 162 */
  { 870, 8, 8, 7, 0, -8 }, /* 0xA3 163 */
  { 878, 8, 6, 6, 0, -7 }, /* 0xA4 164 */
  { 884, 8, 7, 6, 0, -7 }, /* 0xA5 165 */
  { 891, 8, 10, 2, 0, -9 }, /* 0xA6 166 */
  { 901, 8, 9, 5, 0, -9 }, /* 0xA7 167 */
  { 910, 8, 1, 5, 0, -9 }, /* 0xA8 168 */
  { 911, 8, 8, 9, 0, -9 }, /* 0xA9 169 */
  { 919, 8, 7, 6, 0, -9 }, /* 0xAA 170 */
  { 926, 8, 7, 8, 0, -8 }, /* 0xAB 171 */
  { 933, 8, 4, 6, 0, -5 }, /* 0xAC 172 */
  { 937, 8, 1, 5, 0, -5 }, /* 0xAD 173 */
  { 938, 8, 8, 9, 0, -9 }, /* 0xAE 174 */
  { 946, 8, 1, 7, 0, -9 }, /* 0xAF 175 */
  { 947, 8, 4, 5, 0, -9 }, /* 0xB0 176 */
  { 951, 8, 7, 6, 0, -7 }, /* 0xB1 177 */
  { 958, 8, 5, 4, 0, -9 }, /* 0xB2 178 */
  { 963, 8, 5, 4, 0, -9 }, /* 0xB3 179 */
  { 968, 8, 2, 3, 0, -9 }, /* 0xB4 180 */
  { 970, 8, 7, 6, 0, -6 }, /* 0xB5 181 */
  { 977, 8, 8, 6, 0, -8 }, /* 0xB6 182 */
  { 985, 8, 1, 2, 0, -5 }, /* 0xB7 183 */
  { 986, 8, 3, 4, 0, -2 }, /* 0xB8 184 */
  { 989, 8, 5, 4, 0, -9 }, /* 0xB9 185 */
  { 994, 8, 6, 5, 0, -9 }, /* 0xBA 186 */
  { 1000, 8, 7, 8, 0, -8 }, /* 0xBB 187 */
  { 1007, 8, 9, 8, 0, -9 }, /* 0xBC 188 */
  { 1016, 8, 9, 8, 0, -9 }, /* 0xBD 189 */
  { 1025, 8, 10, 8, 0, -9 }, /* 0xBE 190 */
  { 1035, 8, 8, 6, 0, -8 }, /* 0xBF 191 */
  { 1043, 8, 9, 6, 0, -9 }, /* 0xC0 192 */
  { 1052, 8, 9, 6, 0, -9 }, /* 0xC1 193 */
  { 1061, 8, 9, 6, 0, -9 }, /* 0xC2 194 */
  { 1070, 8, 9, 6, 0, -9 }, /* 0xC3 195 */
  { 1079, 8, 9, 6, 0, -9 }, /* 0xC4 196 */
  { 1088, 8, 9, 6, 0, -9 }, /* 0xC5 197 */
  { 1097, 8, 8, 7, 0, -8 }, /* 0xC6 198 */
  { 1105, 8, 9, 7, 0, -8 }, /* 0xC7 199 */
  { 1114, 8, 9, 6, 0, -9 }, /* 0xC8 200 */
  { 1123, 8, 9, 6, 0, -9 }, /* 0xC9 201 */
  { 1132, 8, 9, 6, 0, -9 }, /* 0xCA 202 */
  { 1141, 8, 9, 6, 0, -9 }, /* 0xCB 203 */
  { 1150, 8, 9, 4, 0, -9 }, /* 0xCC 204 */
  { 1159, 8, 9, 4, 0, -9 }, /* 0xCD 205 */
  { 1168, 8, 9, 4, 0, -9 }, /* 0xCE 206 */
  { 1177, 8, 9, 4, 0, -9 }, /* 0xCF 207 */
  { 1186, 8, 8, 7, 0, -8 }, /* 0xD0 208 */
  { 1194, 8, 9, 7, 0, -9 }, /* 0xD1 209 */
  { 1203, 8, 9, 7, 0, -9 }, /* 0xD2 210 */
  { 1212, 8, 9, 7, 0, -9 }, /* 0xD3 211 */
  { 1221, 8, 9, 7, 0, -9 }, /* 0xD4 212 */
  { 1230, 8, 9, 7, 0, -9 }, /* 0xD5 213 */
  { 1239, 8, 9, 7, 0, -9 }, /* 0xD6 214 */
  { 1248, 8, 5, 6, 0, -7 }, /* 0xD7 215 */
  { 1253, 8, 8, 7, 0, -8 }, /* 0xD8 216 */
  { 1261, 8, 9, 6, 0, -9 }, /* 0xD9 217 */
  { 1270, 8, 9, 6, 0, -9 }, /* 0xDA 218 */
  { 1279, 8, 9, 6, 0, -9 }, /* 0xDB 219 */
  { 1288, 8, 9, 6, 0, -9 }, /* 0xDC 220 */
  { 1297, 8, 9, 6, 0, -9 }, /* 0xDD 221 */
  { 1306, 8, 7, 6, 0, -8 }, /* 0xDE 222 */
  { 1313, 8, 8, 6, 0, -8 }, /* 0xDF 223 */
  { 1321, 8, 9, 6, 0, -9 }, /* 0xE0 224 */
  { 1330, 8, 9, 6, 0, -9 }, /* 0xE1 225 */
  { 1339, 8, 9, 6, 0, -9 }, /* 0xE2 226 */
  { 1348, 8, 9, 6, 0, -9 }, /* 0xE3 227 */
  { 1357, 8, 8, 6, 0, -8 }, /* 0xE4 228 */
  { 1365, 8, 8, 6, 0, -8 }, /* 0xE5 229 */
  { 1373, 8, 6, 8, 0, -6 }, /* 0xE6 230 */
  { 1379, 8, 8, 7, 0, -7 }, /* 0xE7 231 */
  { 1387, 8, 9, 6, 0, -9 }, /* 0xE8 232 */
  { 1396, 8, 9, 6, 0, -9 }, /* 0xE9 233 */
  { 1405, 8, 9, 6, 0, -9 }, /* 0xEA 234 */
  { 1414, 8, 8, 6, 0, -8 }, /* 0xEB 235 */
  { 1422, 8, 9, 4, 0, -9 }, /* 0xEC 236 */
  { 1431, 8, 9, 4, 0, -9 }, /* 0xED 237 */
  { 1440, 8, 9, 4, 0, -9 }, /* 0xEE 238 */
  { 1449, 8, 8, 4, 0, -8 }, /* 0xEF 239 */
  { 1457, 8, 9, 8, 0, -9 }, /* 0xF0 240 */
  { 1466, 8, 9, 6, 0, -9 }, /* 0xF1 241 */
  { 1475, 8, 9, 6, 0, -9 }, /* 0xF2 242 */
  { 1484, 8, 9, 6, 0, -9 }, /* 0xF3 243 */
  { 1493, 8, 9, 6, 0, -9 }, /* 0xF4 244 */
  { 1502, 8, 9, 6, 0, -9 }, /* 0xF5 245 */
  { 1511, 8, 8, 6, 0, -8 }, /* 0xF6 246 */
  { 1519, 8, 5, 6, 0, -7 }, /* 0xF7 247 */
  { 1524, 8, 6, 7, 0, -6 }, /* 0xF8 248 */
  { 1530, 8, 9, 6, 0, -9 }, /* 0xF9 249 */
  { 1539, 8, 9, 6, 0, -9 }, /* 0xFA 250 */
  { 1548, 8, 9, 6, 0, -9 }, /* 0xFB 251 */
  { 1557, 8, 8, 6, 0, -8 }, /* 0xFC 252 */
  { 1565, 8, 10, 6, 0, -9 }, /* 0xFD 253 */
  { 1575, 8, 9, 6, 0, -8 }, /* 0xFE 254 */
  { 1584, 8, 9, 6, 0, -8 } /* 0xFF 255 */
};


const GFXfont FoxFont PROGMEM = {
  (uint8_t  *)FoxFontBitmaps,
  (GFXglyph *)FoxFontGlyphs,
  0x20, 0x7E, 10
};
