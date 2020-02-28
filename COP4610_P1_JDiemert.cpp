// COP4610_P1_JDiemert.cpp
// Jairun Dimert
// 02/24/20

#include <iostream>
#include <string>
#include <cmath> 


int numberOfPages(int page, int frame)
{
    return page / frame + 1;
}

int* createAndFillArray(int size)
{
    int* array{ new int[size]{} };
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
    return array;
}

std::string printArray(int* array, int size)
{

    std::string str;
    for (int i = 0; i < size; i++) {
        str += std::to_string(array[i]) + "\n";
    }
    return str;
}

void printPageMapTable(int* array, int size)
{
    std::cout << "The PMT is: \n\n     Page#     Frame#\n--------------------------\n";
    std::string str;
    for (int i = 0; i < size; i++) 
    {
        std::cout << "       " << i << "         " << (array[i]) << "\n";
    }
}

std::string printCountArray(int size)
{
    std::string str;
    int i = 0;
    for (i; i < size - 1; i++) {
        str += std::to_string(i) + ", ";
    }
    str += std::to_string(i);
    return str;
}

int main()
{
    int page;
    int frameSize;
    int* frames;
    int logMemAdd;
    double num;
    int selectedPage;

    std::cout << "Enter the number of locations that the program spans, followed by the page/frame size: \n";
    std::cin >> page >> frameSize;
    std::cout << "Number of pages : " << numberOfPages(page, frameSize)
        << "            Page numbers: 0 - " << numberOfPages(page, frameSize) - 1 << "\n"
        << "Enter the frame numbers for the PMT array: \n";
    frames = createAndFillArray(numberOfPages(page, frameSize));
    printPageMapTable(frames, numberOfPages(page, frameSize));
    std::cout << "Enter the logical memory location in question: ";
    std::cin >> logMemAdd;
    selectedPage = ceil((double)logMemAdd / frameSize);
    std::cout << "\n\n" << logMemAdd << "th logical memory will be on page           = " << logMemAdd << "/page size\n"
        << "                                               = " << logMemAdd << "/" << frameSize << "   = " << (double)logMemAdd / frameSize << "\n"
        << "                                               = " << selectedPage << "(bump up to the higher integer)\n"
        << "Counting from page# 0, the " << selectedPage << "nd/st/th page will be page " << selectedPage - 1 << "(#" << printCountArray(selectedPage) << ")\n"
        << "Number of locations until before the last page = " << frameSize << " x " << selectedPage - 1 << " = " << frameSize * (selectedPage - 1) << " locations\n"
        << "Number of locations in the last page           = " << logMemAdd << " - " << frameSize * (selectedPage - 1) << " = " << logMemAdd - (frameSize * (selectedPage - 1)) << " locations\n"
        << "Starting from an offset of 0, the " << logMemAdd - (frameSize * (selectedPage - 1)) << "nd/st/th location will be at an offset of " << (logMemAdd - (frameSize * (selectedPage - 1))) - 1 << ".\n"
        << "----------------------------------------------------------------------------------\n"
        << "From the start of the memory map:\n"
        << "This page is in Frame " << frames[(selectedPage - 1)] << ", which is the " << (frames[(selectedPage - 1)]) + 1 << "nd/st/th by count as we start from frame# 0\n"
        << "Number of locations covered from start of the map in the first " << frames[selectedPage - 1] << " frames =  " << frames[selectedPage - 1] << " x " << frameSize << " =\n"
        << frames[selectedPage - 1] * frameSize << " locations\n"
        << "The last " << logMemAdd - (frameSize * (selectedPage - 1)) << " locations are in frame# " << frames[selectedPage - 1] << ". Total distance from start = " << frames[selectedPage -1] * frameSize << " + " << logMemAdd - (frameSize * (selectedPage - 1)) << " =\n"
        << (frames[selectedPage - 1] * frameSize) + (logMemAdd - (frameSize * (selectedPage - 1))) << " locations.\n"
        << "So, the " << logMemAdd << "th location by the logical memory is " << (frames[selectedPage - 1] * frameSize) + (logMemAdd - (frameSize * (selectedPage - 1))) << "nd/st/th location in the physical\n"
        << "memory, as per the given PMT.\n\n";

    delete[] frames;
}
