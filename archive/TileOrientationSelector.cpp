#include <iostream>
#include <fstream>
#include <cstdlib> // for exit function
// This program output values from an array to a file named example2.dat

bool compareNeighbors(int p_tileNeigbors[][3], int p_possibleNeighbors[][3])
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (p_possibleNeighbors[r][c] != -1 && p_tileNeigbors[r][c] != p_possibleNeighbors[r][c])
                return false;
        }
    }

    return true;
}

int main()
{
    std::ofstream outdata; // outdata is like cin

    outdata.open("output.txt"); // opens the file
    if (!outdata)
    { // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }

    int frame;

    outdata << "switch(surroundInfo) {" << std::endl;

    for (int i = 0; i < 256; i++)
    {
        int surroundInfo[3][3] = {0};
        int j = i;

        if (j >= 128)
        {
            // Bottom Right
            //     {0, 0, 0}
            //     {0, 0, 0}
            //     {0, 0, 1}
            surroundInfo[2][2] = 1;
            j -= 128;
        }
        if (j >= 64)
        {
            // Bottom Left
            //     {0, 0, 0}
            //     {0, 0, 0}
            //     {1, 0, 0}
            surroundInfo[2][0] = 1;
            j -= 64;
        }
        if (j >= 32)
        {
            // Top Right
            //     {0, 0, 1}
            //     {0, 0, 0}
            //     {0, 0, 0}
            surroundInfo[0][2] = 1;
            j -= 32;
        }
        if (j >= 16)
        {
            // Top Left
            //     {1, 0, 0}
            //     {0, 0, 0}
            //     {0, 0, 0}
            surroundInfo[0][0] = 1;
            j -= 16;
        }
        if (j >= 8)
        {
            // Right
            //     {0, 0, 0}
            //     {0, 0, 1}
            //     {0, 0, 0}
            surroundInfo[1][2] = 1;
            j -= 8;
        }
        if (j >= 4)
        {
            // Left
            //     {0, 0, 0}
            //     {1, 0, 0}
            //     {0, 0, 0}
            surroundInfo[1][0] = 1;
            j -= 4;
        }
        if (j >= 2)
        {
            // Bottom
            //     {0, 0, 0}
            //     {0, 0, 0}
            //     {0, 1, 0}
            surroundInfo[2][1] = 1;
            j -= 2;
        }
        if (j >= 1)
        {
            // Top
            //     {0, 1, 0}
            //     {0, 0, 0}
            //     {0, 0, 0}
            surroundInfo[0][1] = 1;
            j -= 1;
        }

        int env0[3][3] = {
            {-1, 0, -1},
            {0, -1, 0},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env0))
        {
            frame = 0;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env1[3][3] = {
            {-1, 0, -1},
            {0, -1, 1},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env1))
        {
            frame = 1;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env2[3][3] = {
            {-1, 0, -1},
            {1, -1, 1},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env2))
        {
            frame = 2;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env3[3][3] = {
            {-1, 0, -1},
            {1, -1, 0},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env3))
        {
            frame = 3;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env4[3][3] = {
            {-1, 0, -1},
            {0, -1, 1},
            {-1, 1, 0}};
        if (compareNeighbors(surroundInfo, env4))
        {
            frame = 4;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env5[3][3] = {
            {-1, 0, -1},
            {1, -1, 1},
            {0, 1, 0}};
        if (compareNeighbors(surroundInfo, env5))
        {
            frame = 5;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env6[3][3] = {
            {-1, 0, -1},
            {1, -1, 0},
            {0, 1, -1}};
        if (compareNeighbors(surroundInfo, env6))
        {
            frame = 6;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env7[3][3] = {
            {1, 1, 1},
            {1, -1, 1},
            {1, 1, 0}};
        if (compareNeighbors(surroundInfo, env7))
        {
            frame = 7;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env8[3][3] = {
            {-1, 0, -1},
            {0, -1, 0},
            {-1, 1, -1}};
        if (compareNeighbors(surroundInfo, env8))
        {
            frame = 8;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env9[3][3] = {
            {-1, 0, -1},
            {0, -1, 1},
            {-1, 1, 1}};
        if (compareNeighbors(surroundInfo, env9))
        {
            frame = 9;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env10[3][3] = {
            {-1, 0, -1},
            {1, -1, 1},
            {1, 1, 1}};
        if (compareNeighbors(surroundInfo, env10))
        {
            frame = 10;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env11[3][3] = {
            {-1, 0, -1},
            {1, -1, 0},
            {1, 1, -1}};
        if (compareNeighbors(surroundInfo, env11))
        {
            frame = 11;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env12[3][3] = {
            {-1, 1, 0},
            {0, -1, 1},
            {-1, 1, 0}};
        if (compareNeighbors(surroundInfo, env12))
        {
            frame = 12;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env13[3][3] = {
            {0, 1, 0},
            {1, -1, 1},
            {0, 1, 0}};
        if (compareNeighbors(surroundInfo, env13))
        {
            frame = 13;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env14[3][3] = {
            {0, 1, -1},
            {1, -1, 0},
            {0, 1, -1}};
        if (compareNeighbors(surroundInfo, env14))
        {
            frame = 14;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env15[3][3] = {
            {1, 1, 0},
            {1, -1, 1},
            {1, 1, 1}};
        if (compareNeighbors(surroundInfo, env15))
        {
            frame = 15;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env16[3][3] = {
            {-1, 1, -1},
            {0, -1, 0},
            {-1, 1, -1}};
        if (compareNeighbors(surroundInfo, env16))
        {
            frame = 16;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env17[3][3] = {
            {-1, 1, 1},
            {0, -1, 1},
            {-1, 1, 1}};
        if (compareNeighbors(surroundInfo, env17))
        {
            frame = 17;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env18[3][3] = {
            {1, 1, 1},
            {1, -1, 1},
            {1, 1, 1}};
        if (compareNeighbors(surroundInfo, env18))
        {
            frame = 18;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env19[3][3] = {
            {1, 1, -1},
            {1, -1, 0},
            {1, 1, -1}};
        if (compareNeighbors(surroundInfo, env19))
        {
            frame = 19;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env20[3][3] = {
            {-1, 1, 0},
            {0, -1, 1},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env20))
        {
            frame = 20;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env21[3][3] = {
            {0, 1, 0},
            {1, -1, 1},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env21))
        {
            frame = 21;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env22[3][3] = {
            {0, 1, -1},
            {1, -1, 0},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env22))
        {
            frame = 22;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env23[3][3] = {
            {1, 1, 1},
            {1, -1, 1},
            {0, 1, 1}};
        if (compareNeighbors(surroundInfo, env23))
        {
            frame = 23;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env24[3][3] = {
            {-1, 1, -1},
            {0, -1, 0},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env24))
        {
            frame = 24;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env25[3][3] = {
            {-1, 1, 1},
            {0, -1, 1},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env25))
        {
            frame = 25;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env26[3][3] = {
            {1, 1, 1},
            {1, -1, 1},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env26))
        {
            frame = 26;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env27[3][3] = {
            {1, 1, -1},
            {1, -1, 0},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env27))
        {
            frame = 27;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env28[3][3] = {
            {0, 1, 0},
            {1, -1, 1},
            {0, 1, 1}};
        if (compareNeighbors(surroundInfo, env28))
        {
            frame = 28;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env29[3][3] = {
            {0, 1, 0},
            {1, -1, 1},
            {1, 1, 1}};
        if (compareNeighbors(surroundInfo, env29))
        {
            frame = 29;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env30[3][3] = {
            {0, 1, 0},
            {1, -1, 1},
            {1, 1, 0}};
        if (compareNeighbors(surroundInfo, env30))
        {
            frame = 30;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env31[3][3] = {
            {0, 1, 1},
            {1, -1, 1},
            {1, 1, 1}};
        if (compareNeighbors(surroundInfo, env31))
        {
            frame = 31;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env32[3][3] = {
            {-1, 1, 1},
            {0, -1, 1},
            {-1, 1, 0}};
        if (compareNeighbors(surroundInfo, env32))
        {
            frame = 32;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env33[3][3] = {
            {1, 1, 0},
            {1, -1, 1},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env33))
        {
            frame = 33;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env34[3][3] = {
            {0, 1, 1},
            {1, -1, 1},
            {-1, 0, -1}};
        if (compareNeighbors(surroundInfo, env34))
        {
            frame = 34;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env35[3][3] = {
            {1, 1, -1},
            {1, -1, 0},
            {0, 1, -1}};
        if (compareNeighbors(surroundInfo, env35))
        {
            frame = 35;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env36[3][3] = {
            {0, 1, 1},
            {1, -1, 1},
            {0, 1, 1}};
        if (compareNeighbors(surroundInfo, env36))
        {
            frame = 36;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env38[3][3] = {
            {1, 1, 0},
            {1, -1, 1},
            {1, 1, 0}};
        if (compareNeighbors(surroundInfo, env38))
        {
            frame = 38;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env39[3][3] = {
            {0, 1, 1},
            {1, -1, 1},
            {1, 1, 0}};
        if (compareNeighbors(surroundInfo, env39))
        {
            frame = 39;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env40[3][3] = {
            {-1, 1, 0},
            {0, -1, 1},
            {-1, 1, 1}};
        if (compareNeighbors(surroundInfo, env40))
        {
            frame = 40;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env41[3][3] = {
            {-1, 0, -1},
            {1, -1, 1},
            {1, 1, 0}};
        if (compareNeighbors(surroundInfo, env41))
        {
            frame = 41;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env42[3][3] = {
            {-1, 0, -1},
            {1, -1, 1},
            {0, 1, 1}};
        if (compareNeighbors(surroundInfo, env42))
        {
            frame = 42;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env43[3][3] = {
            {0, 1, -1},
            {1, -1, 0},
            {1, 1, -1}};
        if (compareNeighbors(surroundInfo, env43))
        {
            frame = 43;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env44[3][3] = {
            {0, 1, 1},
            {1, -1, 1},
            {0, 1, 0}};
        if (compareNeighbors(surroundInfo, env44))
        {
            frame = 44;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env45[3][3] = {
            {1, 1, 1},
            {1, -1, 1},
            {0, 1, 0}};
        if (compareNeighbors(surroundInfo, env45))
        {
            frame = 45;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env46[3][3] = {
            {1, 1, 0},
            {1, -1, 1},
            {0, 1, 0}};
        if (compareNeighbors(surroundInfo, env46))
        {
            frame = 46;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }

        int env47[3][3] = {
            {1, 1, 0},
            {1, -1, 1},
            {0, 1, 1}};
        if (compareNeighbors(surroundInfo, env47))
        {
            frame = 47;
            outdata << "    case " << i << ":" << std::endl;
            outdata << "        frame = " << frame << ";" << std::endl;
            outdata << "        break;" << std::endl;
            continue;
        }
    }

    outdata << "}" << std::endl;

    outdata.close();

    return 0;
}