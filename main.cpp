#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct MemoryBlock {
    int size;
    bool allocated;
};

class MemoryManager {
private:
    vector<MemoryBlock> memoryBlocks;

public:
    MemoryManager(vector<int> blockSizes) {
        for (int size : blockSizes) {
            memoryBlocks.push_back({size, false});
        }
    }

    void bestFitAllocate(int requestedSize) {
        int bestFitIndex = -1;
        int bestFitSizeDiff = INT_MAX;

        for (int i = 0; i < memoryBlocks.size(); ++i) {
            if (!memoryBlocks[i].allocated && memoryBlocks[i].size >= requestedSize) {
                int sizeDiff = memoryBlocks[i].size - requestedSize;
                if (sizeDiff < bestFitSizeDiff) {
                    bestFitSizeDiff = sizeDiff;
                    bestFitIndex = i;
                }
            }
        }

        if (bestFitIndex != -1) {
            memoryBlocks[bestFitIndex].allocated = true;
            cout << "Allocated memory block of size " << requestedSize << endl;
        } else {
           cout << "No suitable memory block found for size " << requestedSize << endl;
        }
    }
            cout << " " << endl;
            
    void deallocate(int requestedSize) {
        for (auto& block : memoryBlocks) {
            if (block.allocated && block.size == requestedSize) {
                block.allocated = false;
                cout << "Deallocated memory block of size " << requestedSize << endl;
                return;
            }
        }
        cout << "Memory block of size " << requestedSize << " not found." << endl;
    }

    void printMemoryStatus() {
        for (int i = 0; i < memoryBlocks.size(); ++i) {
           cout << "Block " << i << ": Size=" << memoryBlocks[i].size << " Allocated=" << (memoryBlocks[i].allocated ? "Yes" : "No") << std::endl;
        }
    }
};

int main() {
    vector<int> blockSizes = {20, 10, 30, 15};
    MemoryManager memoryManager(blockSizes);

    memoryManager.bestFitAllocate(12);
    memoryManager.bestFitAllocate(25);
    memoryManager.bestFitAllocate(8);
    memoryManager.printMemoryStatus();

    memoryManager.deallocate(20);
    memoryManager.bestFitAllocate(18);
    memoryManager.printMemoryStatus();

    return 0;
}
