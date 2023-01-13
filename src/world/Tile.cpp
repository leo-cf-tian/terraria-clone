#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include <iostream>

#include "Chunk.hpp"
#include "Tile.hpp"

Tile::Tile(Chunk *p_chunk, Vector2 p_pos)
    : chunk(p_chunk), pos(p_pos){};

Tile::Tile(Chunk *p_chunk, Vector2 p_pos, int p_id)
    : chunk(p_chunk), pos(p_pos)
{
    id = p_id;
};

Tile::Tile(Chunk *p_chunk, Vector2 p_pos, int p_id, int p_frame)
    : chunk(p_chunk), pos(p_pos)
{
    id = p_id;
    frame = p_frame;
};

Tile::~Tile(){};

int Tile::getId()
{
    return id;
};

void Tile::setFrame(int p_frame)
{
    frame = p_frame % 16;
};

SDL_Rect Tile::getFrame()
{
    int offsetX = (1 + width) * (frame % 8);
    int offsetY = (1 + height) * floor(frame / 8);

    SDL_Rect src;
    src.x = 1 + offsetX;
    src.y = 1 + offsetY;
    src.w = width;
    src.h = height;

    return src;
};

// TODO: Add tile variants
SDL_Rect Tile::getFrame(int p_variant)
{
    // int offsetX = (1 + width) * (frame % 8);
    // int offsetY = (1 + height) * (floor(frame / 8) + (p_variant % 3) * 8);

    // SDL_Rect src;
    // src.x = 1 + offsetX;
    // src.y = 1 + offsetY;
    // src.w = width;
    // src.h = height;

    return getFrame();
};

void Tile::tileUpdate()
{
    if (id == 0)
        return;

    TileMap tileMap = chunk->getWrappedTileMap();

    int surroundInfo = 0;

    int posX = pos.x + 1;
    int posY = pos.y + 1;

    // Top
    if (posY - 1 >= 0 && tileMap[posX][posY - 1]->getId() != 0)
        surroundInfo += 1;

    // Bottom
    if (posY + 1 <= 65 && tileMap[posX][posY + 1]->getId() != 0)
        surroundInfo += 2;

    // Left
    if (posX - 1 >= 0 && tileMap[posX - 1][posY]->getId() != 0)
        surroundInfo += 4;

    // Right
    if (posX + 1 <= 65 && tileMap[posX + 1][posY]->getId() != 0)
        surroundInfo += 8;

    // Top Left
    if (posY - 1 >= 0 && posX - 1 >= 0 && tileMap[posX - 1][posY - 1]->getId() != 0)
        surroundInfo += 16;

    // Top Right
    if (posY - 1 >= 0 && posX + 1 <= 65 && tileMap[posX + 1][posY - 1]->getId() != 0)
        surroundInfo += 32;

    // Bottom Left
    if (posY + 1 <= 65 && posX - 1 >= 0 && tileMap[posX - 1][posY + 1]->getId() != 0)
        surroundInfo += 64;

    // Bottom Right
    if (posY + 1 <= 65 && posX + 1 <= 65 && tileMap[posX + 1][posY + 1]->getId() != 0)
        surroundInfo += 128;

    // This 256 case long switch statement represents the number of neighboring block states
    // The switch statement was written programatically by an algorithm implemented in archive/TileOrientationSelector
    switch (surroundInfo)
    {
    case 1:
        frame = 24;
        break;
    case 2:
        frame = 8;
        break;
    case 3:
        frame = 16;
        break;
    case 4:
        frame = 3;
        break;
    case 5:
        frame = 22;
        break;
    case 6:
        frame = 6;
        break;
    case 7:
        frame = 14;
        break;
    case 8:
        frame = 1;
        break;
    case 9:
        frame = 20;
        break;
    case 10:
        frame = 4;
        break;
    case 11:
        frame = 12;
        break;
    case 12:
        frame = 2;
        break;
    case 13:
        frame = 21;
        break;
    case 14:
        frame = 5;
        break;
    case 15:
        frame = 13;
        break;
    case 16:
        frame = 0;
        break;
    case 17:
        frame = 24;
        break;
    case 18:
        frame = 8;
        break;
    case 19:
        frame = 16;
        break;
    case 20:
        frame = 3;
        break;
    case 21:
        frame = 27;
        break;
    case 22:
        frame = 6;
        break;
    case 23:
        frame = 35;
        break;
    case 24:
        frame = 1;
        break;
    case 25:
        frame = 20;
        break;
    case 26:
        frame = 4;
        break;
    case 27:
        frame = 12;
        break;
    case 28:
        frame = 2;
        break;
    case 29:
        frame = 33;
        break;
    case 30:
        frame = 5;
        break;
    case 31:
        frame = 46;
        break;
    case 32:
        frame = 0;
        break;
    case 33:
        frame = 24;
        break;
    case 34:
        frame = 8;
        break;
    case 35:
        frame = 16;
        break;
    case 36:
        frame = 3;
        break;
    case 37:
        frame = 22;
        break;
    case 38:
        frame = 6;
        break;
    case 39:
        frame = 14;
        break;
    case 40:
        frame = 1;
        break;
    case 41:
        frame = 25;
        break;
    case 42:
        frame = 4;
        break;
    case 43:
        frame = 32;
        break;
    case 44:
        frame = 2;
        break;
    case 45:
        frame = 34;
        break;
    case 46:
        frame = 5;
        break;
    case 47:
        frame = 44;
        break;
    case 48:
        frame = 0;
        break;
    case 49:
        frame = 24;
        break;
    case 50:
        frame = 8;
        break;
    case 51:
        frame = 16;
        break;
    case 52:
        frame = 3;
        break;
    case 53:
        frame = 27;
        break;
    case 54:
        frame = 6;
        break;
    case 55:
        frame = 35;
        break;
    case 56:
        frame = 1;
        break;
    case 57:
        frame = 25;
        break;
    case 58:
        frame = 4;
        break;
    case 59:
        frame = 32;
        break;
    case 60:
        frame = 2;
        break;
    case 61:
        frame = 26;
        break;
    case 62:
        frame = 5;
        break;
    case 63:
        frame = 45;
        break;
    case 64:
        frame = 0;
        break;
    case 65:
        frame = 24;
        break;
    case 66:
        frame = 8;
        break;
    case 67:
        frame = 16;
        break;
    case 68:
        frame = 3;
        break;
    case 69:
        frame = 22;
        break;
    case 70:
        frame = 11;
        break;
    case 71:
        frame = 43;
        break;
    case 72:
        frame = 1;
        break;
    case 73:
        frame = 20;
        break;
    case 74:
        frame = 4;
        break;
    case 75:
        frame = 12;
        break;
    case 76:
        frame = 2;
        break;
    case 77:
        frame = 21;
        break;
    case 78:
        frame = 41;
        break;
    case 79:
        frame = 30;
        break;
    case 80:
        frame = 0;
        break;
    case 81:
        frame = 24;
        break;
    case 82:
        frame = 8;
        break;
    case 83:
        frame = 16;
        break;
    case 84:
        frame = 3;
        break;
    case 85:
        frame = 27;
        break;
    case 86:
        frame = 11;
        break;
    case 87:
        frame = 19;
        break;
    case 88:
        frame = 1;
        break;
    case 89:
        frame = 20;
        break;
    case 90:
        frame = 4;
        break;
    case 91:
        frame = 12;
        break;
    case 92:
        frame = 2;
        break;
    case 93:
        frame = 33;
        break;
    case 94:
        frame = 41;
        break;
    case 95:
        frame = 38;
        break;
    case 96:
        frame = 0;
        break;
    case 97:
        frame = 24;
        break;
    case 98:
        frame = 8;
        break;
    case 99:
        frame = 16;
        break;
    case 100:
        frame = 3;
        break;
    case 101:
        frame = 22;
        break;
    case 102:
        frame = 11;
        break;
    case 103:
        frame = 43;
        break;
    case 104:
        frame = 1;
        break;
    case 105:
        frame = 25;
        break;
    case 106:
        frame = 4;
        break;
    case 107:
        frame = 32;
        break;
    case 108:
        frame = 2;
        break;
    case 109:
        frame = 34;
        break;
    case 110:
        frame = 41;
        break;
    case 111:
        frame = 39;
        break;
    case 112:
        frame = 0;
        break;
    case 113:
        frame = 24;
        break;
    case 114:
        frame = 8;
        break;
    case 115:
        frame = 16;
        break;
    case 116:
        frame = 3;
        break;
    case 117:
        frame = 27;
        break;
    case 118:
        frame = 11;
        break;
    case 119:
        frame = 19;
        break;
    case 120:
        frame = 1;
        break;
    case 121:
        frame = 25;
        break;
    case 122:
        frame = 4;
        break;
    case 123:
        frame = 32;
        break;
    case 124:
        frame = 2;
        break;
    case 125:
        frame = 26;
        break;
    case 126:
        frame = 41;
        break;
    case 127:
        frame = 7;
        break;
    case 128:
        frame = 0;
        break;
    case 129:
        frame = 24;
        break;
    case 130:
        frame = 8;
        break;
    case 131:
        frame = 16;
        break;
    case 132:
        frame = 3;
        break;
    case 133:
        frame = 22;
        break;
    case 134:
        frame = 6;
        break;
    case 135:
        frame = 14;
        break;
    case 136:
        frame = 1;
        break;
    case 137:
        frame = 20;
        break;
    case 138:
        frame = 9;
        break;
    case 139:
        frame = 40;
        break;
    case 140:
        frame = 2;
        break;
    case 141:
        frame = 21;
        break;
    case 142:
        frame = 42;
        break;
    case 143:
        frame = 28;
        break;
    case 144:
        frame = 0;
        break;
    case 145:
        frame = 24;
        break;
    case 146:
        frame = 8;
        break;
    case 147:
        frame = 16;
        break;
    case 148:
        frame = 3;
        break;
    case 149:
        frame = 27;
        break;
    case 150:
        frame = 6;
        break;
    case 151:
        frame = 35;
        break;
    case 152:
        frame = 1;
        break;
    case 153:
        frame = 20;
        break;
    case 154:
        frame = 9;
        break;
    case 155:
        frame = 40;
        break;
    case 156:
        frame = 2;
        break;
    case 157:
        frame = 33;
        break;
    case 158:
        frame = 42;
        break;
    case 159:
        frame = 47;
        break;
    case 160:
        frame = 0;
        break;
    case 161:
        frame = 24;
        break;
    case 162:
        frame = 8;
        break;
    case 163:
        frame = 16;
        break;
    case 164:
        frame = 3;
        break;
    case 165:
        frame = 22;
        break;
    case 166:
        frame = 6;
        break;
    case 167:
        frame = 14;
        break;
    case 168:
        frame = 1;
        break;
    case 169:
        frame = 25;
        break;
    case 170:
        frame = 9;
        break;
    case 171:
        frame = 17;
        break;
    case 172:
        frame = 2;
        break;
    case 173:
        frame = 34;
        break;
    case 174:
        frame = 42;
        break;
    case 175:
        frame = 36;
        break;
    case 176:
        frame = 0;
        break;
    case 177:
        frame = 24;
        break;
    case 178:
        frame = 8;
        break;
    case 179:
        frame = 16;
        break;
    case 180:
        frame = 3;
        break;
    case 181:
        frame = 27;
        break;
    case 182:
        frame = 6;
        break;
    case 183:
        frame = 35;
        break;
    case 184:
        frame = 1;
        break;
    case 185:
        frame = 25;
        break;
    case 186:
        frame = 9;
        break;
    case 187:
        frame = 17;
        break;
    case 188:
        frame = 2;
        break;
    case 189:
        frame = 26;
        break;
    case 190:
        frame = 42;
        break;
    case 191:
        frame = 23;
        break;
    case 192:
        frame = 0;
        break;
    case 193:
        frame = 24;
        break;
    case 194:
        frame = 8;
        break;
    case 195:
        frame = 16;
        break;
    case 196:
        frame = 3;
        break;
    case 197:
        frame = 22;
        break;
    case 198:
        frame = 11;
        break;
    case 199:
        frame = 43;
        break;
    case 200:
        frame = 1;
        break;
    case 201:
        frame = 20;
        break;
    case 202:
        frame = 9;
        break;
    case 203:
        frame = 40;
        break;
    case 204:
        frame = 2;
        break;
    case 205:
        frame = 21;
        break;
    case 206:
        frame = 10;
        break;
    case 207:
        frame = 29;
        break;
    case 208:
        frame = 0;
        break;
    case 209:
        frame = 24;
        break;
    case 210:
        frame = 8;
        break;
    case 211:
        frame = 16;
        break;
    case 212:
        frame = 3;
        break;
    case 213:
        frame = 27;
        break;
    case 214:
        frame = 11;
        break;
    case 215:
        frame = 19;
        break;
    case 216:
        frame = 1;
        break;
    case 217:
        frame = 20;
        break;
    case 218:
        frame = 9;
        break;
    case 219:
        frame = 40;
        break;
    case 220:
        frame = 2;
        break;
    case 221:
        frame = 33;
        break;
    case 222:
        frame = 10;
        break;
    case 223:
        frame = 15;
        break;
    case 224:
        frame = 0;
        break;
    case 225:
        frame = 24;
        break;
    case 226:
        frame = 8;
        break;
    case 227:
        frame = 16;
        break;
    case 228:
        frame = 3;
        break;
    case 229:
        frame = 22;
        break;
    case 230:
        frame = 11;
        break;
    case 231:
        frame = 43;
        break;
    case 232:
        frame = 1;
        break;
    case 233:
        frame = 25;
        break;
    case 234:
        frame = 9;
        break;
    case 235:
        frame = 17;
        break;
    case 236:
        frame = 2;
        break;
    case 237:
        frame = 34;
        break;
    case 238:
        frame = 10;
        break;
    case 239:
        frame = 31;
        break;
    case 240:
        frame = 0;
        break;
    case 241:
        frame = 24;
        break;
    case 242:
        frame = 8;
        break;
    case 243:
        frame = 16;
        break;
    case 244:
        frame = 3;
        break;
    case 245:
        frame = 27;
        break;
    case 246:
        frame = 11;
        break;
    case 247:
        frame = 19;
        break;
    case 248:
        frame = 1;
        break;
    case 249:
        frame = 25;
        break;
    case 250:
        frame = 9;
        break;
    case 251:
        frame = 17;
        break;
    case 252:
        frame = 2;
        break;
    case 253:
        frame = 26;
        break;
    case 254:
        frame = 10;
        break;
    case 255:
        frame = 18;
        break;
    default:
        frame = 0;
        break;
    }
};