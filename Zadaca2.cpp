#include <iostream>
#include <algorithm>
#include <vector>

struct Process {
    int id;
    int priority;
};

int main() {
    std::vector<Process> processes = {{1, 3}, {2, 2}, {3, 1}, {4, 4}, {5, 2}};

    std::sort(processes.begin(), processes.end(),
              [](const Process& p1, const Process& p2) {
                  return p1.priority < p2.priority;
              });

    std::for_each(processes.begin(), processes.end(),
                  [](const Process& p) {
                      std::cout << "Processing process with id: " << p.id << "\n";
                  });

    return 0;
}
