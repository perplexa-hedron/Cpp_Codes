
vector<int> topKFrequent_heapSort(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap

    unordered_map<int, int> freq;

    for (auto i : nums)
    {
        freq[i]++;
    }

    for (auto i : freq)
    {
        pq.push({i.second, i.first});
        // if pq size > k, removing top min elemet by pop
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> topK;
    while (pq.size())
    {
        topK.push_back(pq.top().second);
        pq.pop();
    }
    return topK;
}