class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calculateGain = [](int passes, int total) -> double {
            return (double)(passes + 1) / (total + 1) - (double)passes / total;
        };

        // Max heap to store (-gain, passes, totalStudents) so we maximize gain
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        // Initialize the heap with each class's initial gain
        for (const auto& cls : classes) {
            int passes = cls[0], total = cls[1];
            maxHeap.push({calculateGain(passes, total), {passes, total}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first, total = classInfo.second;

            // Add one student to this class
            passes++;
            total++;

            // Recalculate the gain and push back into the heap
            maxHeap.push({calculateGain(passes, total), {passes, total}});
        }

        // Calculate the final average pass ratio
        double totalPassRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first, total = classInfo.second;
            totalPassRatio += (double)passes / total;
        }

        return totalPassRatio / classes.size();
    }
};
