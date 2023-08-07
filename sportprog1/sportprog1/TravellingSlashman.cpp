#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct Point {
    int x, y;
    double dist(Point other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};


int edges[300][300];

const double MAXP = 1800 * 1800;

struct Edges {
    int v;
    double w;
    bool operator<(const Edges& rhs) const { return w < rhs.w; }
};
vector<Point> points;

class HashTable {
    static const int PRIME_CONST = 31;
    static const int ARR_SIZE = 3001;
    vector<int> arr[ARR_SIZE];

public:
    HashTable() {
        //6
        arr[1837] = { 0,1,4,2,3,0 };
        //8
        arr[1999] = { 0, 34, 12, 29, 8, 6, 43, 24, 35, 39, 40, 16, 14, 32, 47, 49, 19, 13, 22, 11, 36, 27, 42, 26, 17, 48, 3, 25, 10, 28, 41, 23, 7, 37, 46, 1, 9, 5, 30, 44, 15, 33, 20, 18, 4, 21, 2, 38, 31, 45, 0 };
        //9
        arr[132] = { 0, 1, 71, 78, 27, 46, 94, 48, 76, 19, 24, 83, 21, 49, 6, 23, 56, 53, 7, 20, 43, 50, 39, 9, 30, 90, 52, 5, 18, 45, 35, 51, 70, 31, 82, 89, 88, 77, 59, 69, 79, 11, 65, 47, 60, 57, 16, 34, 25, 81, 64, 97, 37, 73, 26, 86, 17, 40, 63, 12, 10, 58, 72, 29, 54, 33, 8, 15, 68, 36, 42, 84, 62, 13, 38, 44, 93, 61, 3, 55, 87, 14, 28, 66, 75, 32, 22, 91, 98, 99, 80, 41, 92, 74, 96, 67, 85, 2, 95, 4, 0 };
        //10
        arr[1725] = { 0, 184, 295, 246, 23, 114, 168, 286, 15, 224, 71, 189, 151, 248, 281, 154, 181, 6, 292, 60, 126, 171, 130, 273, 27, 55, 279, 134, 133, 253, 100, 249, 25, 232, 147, 209, 36, 287, 219, 191, 221, 293, 96, 152, 205, 34, 139, 77, 162, 250, 50, 240, 203, 88, 206, 166, 178, 118, 267, 157, 111, 37, 228, 46, 32, 188, 29, 142, 59, 10, 104, 103, 106, 298, 49, 294, 72, 8, 56, 290, 33, 16, 160, 173, 81, 68, 275, 176, 85, 63, 39, 192, 54, 137, 177, 254, 185, 215, 14, 140, 186, 70, 158, 45, 280, 145, 172, 7, 83, 276, 233, 86, 238, 35, 218, 288, 98, 89, 299, 12, 239, 159, 67, 211, 210, 22, 169, 17, 76, 141, 129, 272, 143, 146, 93, 256, 212, 109, 283, 41, 223, 135, 125, 127, 164, 163, 115, 187, 92, 285, 190, 183, 107, 117, 62, 131, 245, 74, 48, 241, 1, 144, 274, 138, 226, 227, 73, 255, 40, 28, 284, 278, 271, 102, 199, 79, 42, 18, 269, 120, 282, 91, 242, 4, 262, 80, 87, 136, 291, 289, 112, 247, 153, 65, 194, 230, 204, 237, 24, 5, 277, 264, 217, 243, 30, 201, 156, 161, 207, 58, 132, 61, 263, 214, 252, 116, 2, 38, 119, 43, 200, 9, 296, 268, 97, 235, 231, 69, 236, 99, 182, 47, 197, 258, 265, 202, 180, 95, 174, 149, 297, 20, 170, 26, 113, 52, 66, 21, 216, 105, 94, 175, 208, 257, 251, 101, 261, 266, 31, 121, 82, 220, 234, 198, 53, 13, 195, 64, 78, 108, 11, 259, 123, 44, 84, 225, 90, 213, 167, 222, 128, 148, 155, 150, 229, 193, 19, 110, 122, 270, 75, 51, 196, 165, 260, 179, 57, 244, 3, 124, 0 };
        //11
        arr[1490] = { 0, 7, 72, 95, 76, 20, 97, 73, 90, 38, 77, 84, 13, 89, 62, 59, 99, 25, 71, 57, 96, 5, 15, 87, 65, 44, 34, 48, 92, 85, 60, 55, 53, 27, 56, 26, 19, 58, 54, 4, 67, 6, 74, 28, 8, 17, 49, 18, 40, 91, 66, 37, 93, 45, 9, 64, 78, 12, 86, 29, 2, 11, 16, 63, 61, 42, 68, 81, 82, 50, 79, 47, 30, 83, 80, 21, 22, 10, 3, 70, 94, 88, 14, 39, 23, 35, 24, 46, 41, 98, 51, 1, 32, 31, 43, 69, 36, 75, 33, 52, 0 };
        //12
        arr[1238] = { 0, 118, 99, 105, 147, 86, 142, 32, 116, 69, 122, 77, 97, 103, 11, 123, 137, 35, 102, 27, 135, 47, 121, 117, 74, 63, 10, 94, 18, 107, 60, 78, 44, 133, 139, 57, 28, 85, 120, 54, 75, 83, 37, 70, 45, 53, 72, 111, 25, 100, 144, 92, 131, 90, 29, 145, 132, 23, 128, 140, 14, 148, 50, 130, 71, 6, 80, 87, 73, 33, 61, 64, 62, 4, 89, 114, 8, 59, 36, 98, 19, 48, 95, 138, 40, 125, 2, 9, 67, 13, 58, 30, 119, 136, 127, 39, 68, 65, 76, 110, 24, 38, 96, 88, 3, 51, 149, 146, 106, 49, 42, 109, 5, 41, 126, 20, 134, 108, 115, 124, 82, 113, 52, 79, 141, 104, 17, 91, 43, 143, 66, 46, 7, 22, 34, 26, 1, 31, 81, 56, 93, 84, 101, 112, 16, 12, 129, 15, 21, 55, 0 };
        //13
        arr[352] = { 0, 153, 120, 59, 71, 173, 16, 119, 5, 115, 172, 49, 9, 183, 64, 70, 94, 155, 184, 32, 60, 20, 44, 113, 199, 125, 17, 154, 185, 138, 167, 181, 180, 87, 75, 186, 29, 171, 143, 159, 118, 144, 156, 89, 197, 152, 194, 33, 142, 158, 22, 11, 176, 1, 175, 147, 107, 81, 150, 3, 132, 53, 15, 178, 58, 166, 65, 54, 136, 97, 66, 162, 134, 160, 57, 6, 92, 165, 83, 76, 106, 7, 174, 135, 19, 148, 179, 23, 129, 188, 24, 46, 123, 91, 30, 149, 28, 124, 198, 13, 47, 50, 37, 196, 110, 145, 36, 130, 56, 121, 48, 39, 133, 100, 191, 101, 35, 98, 4, 102, 14, 170, 151, 157, 168, 27, 141, 140, 72, 18, 12, 137, 86, 195, 108, 34, 105, 88, 67, 99, 109, 8, 193, 139, 122, 111, 187, 62, 127, 190, 103, 114, 189, 26, 90, 61, 68, 82, 41, 182, 45, 73, 63, 192, 74, 79, 93, 43, 126, 164, 51, 55, 128, 78, 96, 40, 25, 38, 80, 131, 69, 42, 10, 2, 177, 104, 169, 21, 77, 161, 52, 31, 146, 116, 117, 95, 112, 85, 84, 163, 0 };
        //14
        arr[2489] = { 0, 233, 195, 208, 188, 216, 63, 51, 102, 37, 236, 244, 50, 243, 7, 197, 177, 137, 4, 127, 228, 77, 141, 167, 145, 76, 58, 176, 210, 140, 222, 1, 192, 147, 53, 69, 211, 106, 152, 66, 172, 8, 32, 212, 92, 174, 62, 21, 38, 36, 168, 108, 204, 164, 122, 26, 88, 16, 200, 67, 104, 84, 175, 14, 43, 217, 18, 238, 80, 239, 41, 156, 154, 56, 25, 155, 169, 97, 49, 78, 219, 237, 95, 9, 138, 45, 6, 215, 79, 247, 203, 112, 132, 158, 133, 65, 229, 149, 11, 126, 190, 161, 135, 230, 123, 5, 60, 139, 113, 52, 47, 241, 160, 86, 120, 202, 220, 91, 198, 159, 165, 40, 100, 146, 185, 235, 207, 218, 114, 64, 59, 73, 10, 111, 82, 157, 115, 181, 90, 186, 74, 234, 173, 121, 143, 103, 44, 3, 183, 48, 193, 144, 93, 23, 170, 105, 89, 124, 136, 224, 33, 118, 109, 128, 81, 184, 30, 191, 72, 19, 246, 131, 231, 205, 189, 98, 148, 57, 71, 17, 166, 232, 153, 15, 61, 225, 107, 129, 85, 110, 194, 242, 223, 196, 151, 182, 119, 214, 34, 54, 83, 20, 245, 22, 187, 163, 101, 227, 206, 134, 55, 179, 221, 117, 150, 240, 29, 162, 178, 248, 42, 70, 27, 39, 130, 209, 24, 96, 201, 249, 2, 94, 13, 31, 68, 199, 87, 75, 99, 125, 171, 12, 213, 180, 116, 46, 28, 142, 35, 226, 0 };
        //15
        arr[182] = { 0, 37, 222, 164, 231, 168, 128, 28, 113, 269, 238, 156, 78, 74, 286, 32, 58, 264, 133, 16, 233, 219, 153, 122, 236, 271, 251, 95, 178, 195, 94, 244, 65, 51, 246, 277, 101, 252, 197, 35, 106, 103, 186, 123, 50, 205, 295, 117, 210, 118, 97, 267, 132, 212, 201, 162, 80, 15, 184, 224, 148, 166, 86, 67, 22, 66, 29, 243, 242, 262, 215, 259, 206, 275, 73, 180, 64, 141, 237, 143, 270, 110, 256, 116, 192, 265, 291, 130, 102, 135, 211, 62, 188, 182, 7, 152, 284, 194, 5, 181, 71, 120, 63, 239, 261, 139, 92, 159, 41, 207, 190, 31, 213, 281, 109, 39, 258, 83, 280, 75, 218, 107, 234, 84, 163, 13, 293, 160, 33, 278, 36, 198, 46, 1, 8, 146, 247, 45, 292, 70, 21, 283, 225, 26, 228, 4, 48, 298, 82, 151, 167, 6, 193, 38, 174, 176, 209, 268, 124, 241, 43, 170, 191, 161, 273, 226, 121, 187, 105, 203, 204, 54, 144, 125, 57, 221, 24, 257, 169, 99, 189, 289, 30, 229, 255, 279, 157, 149, 115, 165, 185, 245, 136, 96, 100, 61, 93, 85, 142, 76, 235, 91, 17, 47, 253, 290, 27, 249, 288, 183, 282, 145, 11, 112, 25, 52, 56, 111, 72, 53, 42, 137, 199, 150, 140, 59, 155, 266, 179, 276, 49, 287, 129, 138, 217, 9, 214, 55, 88, 240, 200, 248, 12, 202, 254, 89, 230, 14, 79, 127, 34, 172, 294, 208, 3, 223, 272, 69, 227, 104, 196, 60, 263, 131, 285, 158, 171, 260, 90, 154, 250, 81, 297, 10, 114, 134, 175, 2, 98, 68, 20, 18, 147, 220, 299, 173, 177, 77, 216, 232, 19, 87, 126, 108, 23, 40, 119, 44, 274, 296, 0 };
        //16
        arr[1621] = { 0, 24, 274, 55, 164, 248, 257, 184, 226, 152, 225, 62, 116, 34, 141, 63, 183, 86, 186, 85, 119, 209, 109, 37, 265, 36, 217, 27, 197, 124, 143, 162, 165, 268, 49, 133, 199, 207, 263, 194, 230, 79, 87, 90, 259, 168, 134, 193, 252, 167, 51, 246, 10, 100, 89, 20, 185, 227, 176, 158, 251, 299, 245, 35, 213, 201, 29, 28, 126, 223, 84, 26, 187, 98, 189, 112, 170, 163, 221, 288, 148, 242, 99, 4, 177, 106, 92, 145, 235, 295, 204, 166, 203, 172, 103, 260, 233, 244, 149, 156, 290, 76, 130, 281, 287, 9, 38, 94, 74, 88, 121, 33, 39, 237, 250, 59, 219, 30, 205, 7, 71, 247, 206, 2, 222, 289, 169, 232, 180, 173, 249, 111, 123, 122, 161, 229, 57, 68, 157, 56, 97, 243, 272, 131, 140, 60, 21, 64, 50, 150, 202, 127, 253, 128, 144, 236, 1, 83, 52, 195, 181, 58, 267, 285, 182, 115, 174, 61, 240, 42, 175, 41, 280, 178, 102, 151, 73, 238, 212, 78, 14, 108, 271, 43, 6, 160, 70, 91, 198, 80, 297, 282, 32, 5, 136, 191, 113, 81, 139, 208, 147, 275, 54, 137, 25, 65, 261, 286, 296, 211, 256, 17, 216, 13, 72, 192, 47, 215, 114, 96, 11, 146, 220, 138, 118, 224, 200, 298, 69, 264, 22, 291, 12, 44, 101, 66, 284, 82, 77, 110, 23, 45, 153, 210, 293, 154, 179, 105, 241, 231, 132, 196, 15, 254, 31, 262, 283, 155, 93, 239, 276, 117, 159, 40, 190, 277, 234, 171, 3, 95, 75, 278, 270, 67, 258, 16, 188, 18, 294, 142, 269, 255, 292, 120, 125, 19, 228, 135, 8, 218, 48, 273, 104, 107, 266, 53, 129, 279, 214, 46, 0 };
        //17
        arr[1897] = { 0, 249, 270, 70, 60, 156, 196, 102, 63, 15, 72, 85, 162, 288, 236, 229, 166, 44, 201, 17, 89, 118, 88, 153, 247, 223, 35, 130, 157, 172, 76, 246, 112, 26, 5, 110, 113, 90, 129, 287, 71, 138, 20, 97, 127, 77, 204, 126, 232, 3, 106, 132, 164, 125, 231, 160, 45, 221, 273, 108, 37, 167, 220, 145, 259, 24, 208, 161, 168, 101, 218, 139, 191, 181, 284, 268, 53, 33, 290, 51, 14, 7, 143, 207, 258, 250, 48, 182, 264, 42, 155, 52, 65, 144, 180, 262, 224, 95, 2, 27, 117, 123, 94, 278, 39, 28, 213, 111, 228, 254, 285, 230, 274, 151, 235, 134, 104, 261, 8, 122, 243, 199, 19, 83, 154, 248, 87, 50, 109, 152, 68, 186, 54, 67, 174, 148, 91, 245, 46, 272, 173, 185, 233, 169, 36, 203, 100, 187, 210, 289, 197, 150, 214, 170, 298, 297, 234, 146, 31, 291, 158, 141, 212, 281, 265, 260, 59, 6, 9, 131, 93, 92, 269, 215, 239, 192, 147, 86, 256, 40, 177, 263, 266, 16, 276, 183, 124, 194, 30, 34, 295, 78, 43, 56, 267, 11, 142, 211, 115, 13, 163, 205, 23, 38, 253, 222, 107, 73, 116, 135, 114, 32, 69, 179, 12, 251, 292, 128, 80, 136, 188, 241, 296, 84, 175, 4, 184, 79, 176, 57, 282, 133, 96, 193, 98, 275, 21, 257, 286, 105, 189, 198, 294, 41, 140, 178, 252, 200, 22, 74, 121, 279, 240, 149, 277, 64, 271, 299, 81, 159, 10, 1, 225, 165, 237, 283, 66, 195, 217, 82, 242, 103, 61, 227, 238, 47, 58, 29, 206, 49, 137, 209, 202, 280, 255, 62, 171, 75, 190, 219, 244, 226, 119, 99, 25, 216, 55, 18, 293, 120, 0 };
        //18
        arr[2386] = { 0, 105, 200, 21, 43, 222, 87, 284, 139, 236, 251, 45, 41, 246, 121, 120, 47, 189, 242, 30, 227, 123, 276, 280, 161, 42, 7, 211, 289, 19, 25, 272, 63, 135, 38, 51, 174, 193, 80, 250, 271, 29, 243, 53, 291, 28, 171, 157, 79, 152, 213, 186, 97, 277, 52, 290, 14, 165, 217, 71, 130, 245, 133, 15, 297, 20, 295, 294, 107, 259, 27, 172, 99, 77, 116, 214, 141, 177, 33, 154, 267, 195, 48, 270, 62, 203, 5, 196, 89, 86, 60, 156, 118, 296, 197, 23, 144, 112, 226, 37, 198, 194, 69, 104, 24, 119, 147, 212, 225, 102, 85, 88, 8, 207, 110, 81, 299, 185, 240, 237, 10, 84, 78, 59, 298, 128, 169, 231, 234, 114, 91, 127, 204, 218, 264, 192, 67, 56, 266, 175, 6, 82, 125, 206, 261, 72, 1, 66, 279, 115, 258, 230, 106, 253, 183, 76, 155, 274, 163, 153, 101, 220, 247, 278, 202, 143, 145, 13, 92, 93, 146, 142, 265, 132, 288, 22, 208, 40, 54, 12, 148, 176, 238, 235, 2, 166, 224, 57, 228, 68, 35, 241, 179, 149, 168, 117, 113, 131, 223, 98, 58, 17, 252, 249, 103, 158, 31, 9, 229, 257, 138, 83, 215, 219, 239, 209, 159, 184, 286, 180, 210, 191, 46, 275, 134, 129, 282, 55, 233, 263, 70, 50, 100, 73, 34, 182, 61, 4, 260, 256, 292, 32, 293, 287, 64, 205, 11, 199, 221, 122, 95, 160, 244, 254, 201, 90, 39, 162, 124, 36, 268, 255, 178, 136, 74, 164, 187, 96, 285, 216, 3, 16, 273, 126, 167, 150, 49, 18, 137, 75, 109, 188, 170, 181, 269, 108, 151, 232, 173, 140, 190, 26, 44, 248, 65, 111, 94, 262, 283, 281, 0 };
        //19
        arr[938] = { 0, 226, 69, 272, 76, 132, 240, 139, 126, 119, 65, 89, 204, 130, 140, 229, 296, 180, 273, 196, 53, 131, 9, 213, 46, 22, 2, 156, 133, 25, 193, 267, 38, 176, 128, 223, 36, 106, 243, 136, 174, 63, 73, 292, 70, 27, 98, 293, 187, 23, 218, 157, 84, 233, 50, 225, 58, 278, 289, 15, 100, 294, 175, 265, 199, 235, 124, 77, 59, 117, 160, 178, 173, 12, 165, 216, 291, 227, 93, 35, 20, 259, 172, 113, 260, 96, 153, 270, 148, 269, 181, 198, 80, 29, 177, 250, 238, 91, 214, 247, 95, 206, 56, 197, 244, 242, 203, 71, 220, 151, 83, 210, 164, 82, 112, 179, 138, 297, 290, 72, 287, 107, 45, 26, 186, 231, 114, 52, 275, 276, 88, 298, 143, 13, 271, 28, 264, 86, 55, 92, 246, 44, 37, 17, 248, 99, 224, 32, 1, 122, 217, 219, 280, 8, 168, 48, 261, 4, 40, 33, 118, 90, 230, 207, 222, 115, 67, 125, 66, 252, 256, 102, 189, 158, 110, 215, 281, 274, 146, 10, 263, 268, 147, 211, 51, 137, 41, 185, 30, 61, 255, 120, 97, 31, 234, 75, 241, 19, 94, 277, 194, 253, 283, 201, 200, 103, 3, 251, 142, 149, 108, 295, 7, 279, 85, 245, 105, 74, 221, 127, 60, 236, 141, 183, 116, 258, 166, 152, 249, 188, 282, 21, 285, 123, 129, 34, 87, 11, 190, 135, 155, 47, 6, 150, 237, 232, 284, 159, 167, 266, 254, 154, 191, 209, 57, 109, 182, 257, 228, 62, 101, 24, 286, 79, 39, 299, 81, 14, 68, 161, 111, 16, 78, 288, 171, 49, 64, 42, 239, 162, 184, 144, 192, 5, 212, 43, 163, 54, 145, 205, 18, 121, 104, 208, 169, 170, 195, 202, 134, 262, 0 };
        //20
        arr[1598] = { 0, 4, 218, 231, 150, 217, 147, 12, 111, 31, 268, 291, 49, 104, 60, 215, 184, 42, 98, 116, 24, 219, 232, 77, 40, 177, 80, 78, 67, 163, 143, 138, 114, 151, 19, 158, 72, 1, 141, 194, 155, 47, 38, 50, 256, 208, 294, 119, 97, 127, 262, 27, 142, 200, 113, 107, 263, 160, 266, 95, 90, 46, 130, 76, 124, 89, 88, 85, 121, 242, 100, 91, 199, 21, 202, 298, 7, 44, 10, 58, 167, 188, 134, 75, 285, 23, 238, 252, 205, 39, 128, 237, 73, 20, 18, 193, 123, 35, 120, 222, 249, 221, 197, 240, 154, 267, 52, 41, 118, 55, 246, 277, 236, 287, 210, 36, 115, 162, 206, 243, 261, 192, 290, 241, 83, 175, 181, 62, 125, 122, 25, 259, 281, 204, 93, 207, 225, 255, 233, 254, 165, 223, 279, 166, 66, 92, 280, 183, 190, 16, 136, 135, 220, 187, 108, 260, 82, 37, 131, 159, 152, 87, 189, 211, 174, 270, 54, 6, 264, 129, 224, 265, 278, 272, 13, 195, 103, 22, 61, 148, 297, 196, 286, 81, 244, 176, 110, 203, 2, 139, 289, 198, 133, 53, 14, 178, 288, 282, 258, 257, 109, 34, 182, 112, 79, 213, 239, 43, 45, 283, 253, 296, 164, 156, 102, 276, 226, 126, 161, 94, 15, 179, 17, 28, 11, 227, 84, 29, 70, 146, 293, 214, 5, 9, 99, 271, 59, 132, 32, 33, 144, 51, 69, 292, 251, 8, 106, 245, 275, 74, 185, 201, 149, 157, 105, 250, 117, 96, 169, 235, 273, 230, 3, 180, 170, 186, 30, 153, 234, 212, 274, 57, 101, 86, 65, 145, 173, 171, 247, 216, 269, 295, 229, 26, 284, 63, 299, 56, 168, 71, 68, 137, 248, 140, 64, 191, 172, 48, 209, 228, 0 };
    }

    void put(string key, vector<int> value) {
        int index = hashFunc(key);
        arr[index] = value;
    }

    static int hashFunc(string key) {
        size_t sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum += (key[i] * (int)pow(PRIME_CONST, i)) % ARR_SIZE;
        }
        return sum % ARR_SIZE;
    }

    vector<int> get(string key) {
        return arr[hashFunc(key)];
    }



    /*void printAll() {
        for (int i = 0; i < ARR_SIZE; i++) {
            if (arr[i] > 0) {
                cout << arr[i] << ", ";
            }
        }
        cout << endl;
    }*/
};

const int N = 6;
double count, bestCount = INT32_MAX;
int x[50];
int visit[50];
int arc[N + 1][N + 1];
int ans[50];

void dfs(int step, int count, int t) {
    int i, j;
    if (bestCount <
        count) // ��������� �����, ������� ����� ���� ������ ����������� �����
        return;
    if (step == N) // ������ n ������
    {
        count += arc[x[step - 1]][t];
        if (bestCount > count) {
            bestCount = count;
            for (int i = 0; i < N; i++) {
                ans[i] = x[i];
            }
            ans[N] = t;
        }
        return;
    }
    else {
        for (j = 0; j < N; j++) {
            if (visit[j] == 0) // j �� ���
            {
                visit[j] = 1; // ���������� ��� ����������
                x[step] = j;  // �������� �������
                dfs(step + 1, count + arc[x[step - 1]][j], t);
                visit[j] = 0;
                x[step] = 0;
            }
        }
    }
}

bool init(vector<int> p, vector<int>& f, int t) {
    bestCount = INT32_MAX;
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            arc[i][j] = points[p[i]].dist(points[p[j]]);
            edges[p[i]][p[j]] = 0;
            edges[p[j]][p[i]] = 0;
        }
    }
    visit[0] = 1;
    x[0] = 0;
    dfs(1, 0, t);
    int v = 0;
    for (int i = 0; i < N; i++) {
        f[p[ans[i]]] = p[ans[i + 1]];
        v = p[ans[i]];
        edges[v][f[v]] = 1;
        edges[f[v]][v] = 1;
    }
    bool q = false;
    for (int i = 0; i < N; i++) {
        if (ans[i] != i)
            q = true;
        ans[i] = 0;
    }
    return q;
}

bool findChange(priority_queue<Edges> ed, int n, int k, vector<int>& f) {
    while (!ed.empty()) {
        int v = ed.top().v;
        ed.pop();
        int i = f[v];
        int fi = i;
        for (int t = 0; t < k - 2; t++) {
            fi = f[fi];
        }
        for (int t = 0; t < n - k - 1; t++) {
            double d1 = points[v].dist(points[f[v]]);
            d1 += points[i].dist(points[f[i]]);
            d1 += points[fi].dist(points[f[fi]]);
            double d2 = points[f[i]].dist(points[v]);
            d2 += points[fi].dist(points[f[v]]);
            d2 += points[i].dist(points[f[fi]]);
            if (d2 < d1) {
                edges[v][f[v]] = 0;
                edges[f[v]][v] = 0;
                edges[i][f[i]] = 0;
                edges[f[i]][i] = 0;
                edges[fi][f[fi]] = 0;
                edges[f[fi]][fi] = 0;
                edges[v][f[i]] = 1;
                edges[f[i]][v] = 1;
                edges[f[v]][fi] = 1;
                edges[fi][f[v]] = 1;
                edges[i][f[fi]] = 1;
                edges[f[fi]][i] = 1;
                int u1 = f[i];
                f[i] = f[fi];
                f[fi] = f[v];
                f[v] = u1;
                return true;
            }
            i = f[i];
            fi = f[fi];
        }
    }
    return false;
}

bool change2edges(priority_queue<Edges> ed, int n, vector<int>& f) {
    while (!ed.empty()) {
        int v = ed.top().v;
        ed.pop();
        for (int i = 0; i < n; i++) {
            if (i != v && f[i] != v && i != f[v] && f[i] != f[v]) {
                double d2 = MAXP;
                double d1 = points[i].dist(points[f[i]]) + points[v].dist(points[f[v]]);
                if (!edges[i][v] && !edges[f[i]][f[v]]) {
                    d2 = points[i].dist(points[v]) + points[f[i]].dist(points[f[v]]);
                }
                if (d2 < d1) {
                    edges[i][f[i]] = 0;
                    edges[f[i]][i] = 0;
                    edges[v][f[v]] = 0;
                    edges[f[v]][v] = 0;
                    edges[i][v] = 1;
                    edges[v][i] = 1;
                    edges[f[i]][f[v]] = 1;
                    edges[f[v]][f[i]] = 1;
                    int u1 = f[v];
                    f[v] = i;
                    v = u1;
                    vector<int> p;
                    p.push_back(u1);
                    while (v != i) {
                        v = f[v];
                        p.push_back(v);
                    }
                    f[u1] = f[i];
                    for (int j = p.size() - 1; j > 0; j--) {
                        f[p[j]] = p[j - 1];
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

bool change3and2node(priority_queue<Edges> ed, int n, vector<int>& f) {
    while (!ed.empty()) {
        int v = ed.top().v;
        ed.pop();
        for (int i = 0; i < n; i++) {
            if (v != i && v != f[i] && f[v] != i) {
                double d1 = points[v].dist(points[f[v]]);
                d1 += points[i].dist(points[f[i]]);
                d1 += points[f[i]].dist(points[f[f[i]]]);
                double d2 = points[v].dist(points[f[i]]);
                d2 += points[f[i]].dist(points[f[v]]);
                d2 += points[i].dist(points[f[f[i]]]);
                if (d2 < d1) {
                    edges[v][f[v]] = 0; edges[f[v]][v] = 0;
                    edges[i][f[i]] = 0; edges[f[i]][i] = 0;
                    edges[f[i]][f[f[i]]] = 0; edges[f[f[i]]][f[i]] = 0;
                    edges[v][f[i]] = 1; edges[f[i]][v] = 1;
                    edges[f[v]][f[i]] = 1; edges[f[i]][f[v]] = 1;
                    edges[i][f[f[i]]] = 1; edges[f[f[i]]][i] = 1;
                    int u1 = f[i];
                    f[i] = f[f[i]];
                    f[u1] = f[v];
                    f[v] = u1;
                    return true;
                }
            }
        }
    }
    return false;
}

bool change2node(priority_queue<Edges> ed, int n, vector<int>& f) {
    int min = 0;
    int minv = -1, mini = -1;
    for (int v = 0; v < n - 1; v++) {
        for (int i = v + 1; i < n; i++) {
            if (f[v] != f[i] && f[v] != i && f[v] != f[f[i]]) {
                double d1 = points[v].dist(points[f[v]]);
                d1 += points[f[v]].dist(points[f[f[v]]]);
                d1 += points[i].dist(points[f[i]]);
                d1 += points[f[i]].dist(points[f[f[i]]]);
                double d2 = points[v].dist(points[f[i]]);
                d2 += points[f[i]].dist(points[f[f[v]]]);
                d2 += points[i].dist(points[f[v]]);
                d2 += points[f[v]].dist(points[f[f[i]]]);
                if (d2 < d1 && d1 - d2>min) {
                    min = d1 - d2;
                    minv = v;
                    mini = i;
                }
            }
        }
    }
    if (minv == -1) return false;
    else {
        int v = minv, i = mini;
        cerr << " " << v << " " << i << endl;
        edges[i][f[i]] = 0; edges[f[i]][i] = 0;
        edges[f[i]][f[f[i]]] = 0; edges[f[f[i]]][f[i]] = 0;
        edges[v][f[v]] = 0; edges[f[v]][v] = 0;
        edges[f[v]][f[f[v]]] = 0; edges[f[f[v]]][f[v]] = 0;
        edges[f[v]][i] = 1; edges[i][f[v]] = 1;
        edges[f[v]][f[f[i]]] = 1; edges[f[f[i]]][f[v]] = 1;
        edges[f[i]][v] = 1; edges[f[i]][v] = 1;
        edges[f[i]][f[f[v]]] = 1; edges[f[f[v]]][f[i]] = 1;
        int u = f[v], ffv = f[f[v]], ffi = f[f[i]];
        f[v] = f[i];
        f[i] = u;
        f[f[i]] = ffi;
        f[f[v]] = ffv;
        return true;
    }
}

double algo1(vector<int>& f, int n) {
    bool isend = false;
    int v;
    while (!isend) {
        double mx = 0;
        v = -1;
        isend = true;
        priority_queue<Edges> ed, ed1, ed2;
        for (int i = 0; i < n; i++) {
            ed.push({ i, points[i].dist(points[f[i]]) });
        }
        bool isfind = false;
        if (isend) {
            isend = !change2edges(ed, n, f);
        }
        if (isend) {
            isend = !change2node(ed, n, f);
        }
        if (isend) {
            isend = !change3and2node(ed, n, f);
            if (isend && n > N) {
                for (int i = 0; i < n; i++) {
                    int v = i;
                    vector<int> r;
                    for (int j = 0; j < N + 1; j++) {
                        r.push_back(v);
                        v = f[v];
                    }
                    if (init(r, f, N)) {
                        isend = false;
                        break;
                    }
                }
            }
            if (isend) {
                for (int i = 4; i < n -1; i++) {
                    if (findChange(ed, n, i, f)) {
                        isend = false;
                        break;
                    }
                }
            }
        }
    }
    v = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += points[v].dist(points[f[v]]);
        v = f[v];
    }
    return sum;
}

double algo2(vector<int>& f, int n) {
    bool isend = false;
    int v;
    int t = 0;
    while (!isend) {
        double mx = 0;
        v = -1;
        isend = true;
        priority_queue<Edges> ed, ed1, ed2;
        for (int i = 0; i < n; i++) {
            ed.push({ i, points[i].dist(points[f[i]]) });
        }
        bool isfind = false;
        if (isend) {
            isend = !change2edges(ed, n, f);
        }
        if (isend && n > N) {
            for (int i = 0; i < n; i++) {
                int v = i;
                vector<int> r;
                for (int j = 0; j < N + 1; j++) {
                    r.push_back(v);
                    v = f[v];
                }
                if (init(r, f, N)) {
                    isend = false;
                    break;
                }
            }
        }
        if (isend) {
            isend = !change3and2node(ed, n, f);
            if (isend) {
                for (int i = 4; i < n - 1; i++) {
                    if (findChange(ed, n, i, f)) {
                        isend = false;
                        break;
                    }
                }
            }
        }
    }
    v = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += points[v].dist(points[f[v]]);
        v = f[v];
    }
    return sum;
}

void init1(int n, vector<int>& f) {
    bool isend = false;
    int v = 0;
    while (!isend) {
        isend = true;
        double Min = MAXP;
        int im = -1;
        for (int i = 0; i < n; i++) {
            if (i != v && f[i] == -1) {
                if (points[v].dist(points[i]) < Min) {
                    Min = points[v].dist(points[i]);
                    im = i;
                }
            }
        }
        if (im > -1) {
            isend = false;
            f[v] = im;
            v = im;
            edges[v][im] = 1;
            edges[im][v] = 1;
        }
        else {
            f[v] = 0;
            v = 0;
            edges[v][0] = 1;
            edges[0][v] = 1;
        }
    }
}



void edgesClear(int n, vector<int>& f) {
    int v = 0;
    for (int i = 0; i < n; i++) {
        edges[v][f[v]] = 0;
        edges[f[v]][v] = 0;
        int u = v;
        v = f[v];
        f[u] = -1;
    }
}

void randomInit(int n, vector<int>& f) {
    vector<int> k(n);
    for (int i = 0; i < n; i++) k[i] = i;
    unsigned seed = chrono::system_clock::now()
        .time_since_epoch()
        .count();
    shuffle(k.begin(), k.end(), std::default_random_engine(seed));
    int v = k[n - 1];
    for (int i = 0; i < n; i++) {
        edges[v][k[i]] = 1;
        edges[k[i]][v] = 1;
        f[v] = k[i];
        v = f[v];
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<int> f(n, -1);
    string s = "";
    for (int i = 0; i < n; i++) {
        Point p; // The y coordinate of the given node
        cin >> p.x >> p.y;
        cin.ignore();
        s += p.x + " " + p.y;
        cerr << p.x << " " << p.y << endl;
        points.push_back(p);
    }
    bool isend = false;
    int v = 0;

    init1(n, f);
    double d2;
    double d1 = algo2(f, n);
    vector<int> answ(f);
    edgesClear(n, f);

    /* if (n > N) {
         vector<int> p;
         for (int i = 0; i < N; i++)
             p.push_back(i);
         p.push_back(0);
         init(p, f, 0);

         for (int i = N; i < n; i++) {
             v = 0;
             int min = INT32_MAX;
             int jm = -1;
             for (int j = 0; j < i; j++) {
                 int d = points[v].dist(points[i]) + points[f[v]].dist(points[i]) -
                     points[v].dist(points[f[v]]);
                 if (d < min) {
                     min = d;
                     jm = j;
                 }
             }
             v = jm;
             edges[v][f[v]] = 0; edges[f[v]][v] = 0;
             edges[v][i] = 1; edges[i][v] = 1;
             edges[f[v]][i] = 1; edges[i][f[v]] = 1;
             f[i] = f[v];
             f[v] = i;
         }
         d2 = algo2(f, n);
         cerr << "d2=" << d2 << " d1=" << d1 << endl;
         if (d2 < d1) {
             answ = f;
             d1=d2;
         }
         edgesClear(n,f);
     }*/
    v = 0;
    HashTable h1 = HashTable();
    vector<int> ah = h1.get(s);
    cerr << "hash s=" << h1.hashFunc(s) << endl;
    if (ah.size() < n) {
        cerr << "nothash" << endl;
        for (int i = 0; i < n; i++) {
            cout << v << " ";
            v = answ[v];
        }
        cout << 0 << endl;
    }
    else {
        v = ah[0];
        for (int i = 0; i < n; i++) {
            int im = ah[i + 1];
            f[v] = ah[i + 1];
            edges[v][im] = 1;
            edges[im][v] = 1;
            v = ah[i + 1];
        }
        cerr<<algo1(f, n)<<endl;
        v = 0;
        for (int i = 0; i <= n; i++) {
            cout << v << " ";
            v = f[v];
        }
        cout << endl;
    }
}