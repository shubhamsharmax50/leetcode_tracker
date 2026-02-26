// Last updated: 26/2/2026, 9:12:38 pm
class NumberContainers{
public:
unordered_map<int, int> idxToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;

        NumberContainers() {
                //do nothing    
                    }
                        
                            void change(int index, int number) {
                                    idxToNum[index] = number; //O(1)

                                            numToIdx[number].push(index); //O(log(n))
                                                }
                                                    
                                                        int find(int number) {
                                                                if(!numToIdx.count(number)) {
                                                                            return -1;
                                                                                    }

                                                                                            auto& pq = numToIdx[number];

                                                                                                    while(!pq.empty()) { //O(k * logn)
                                                                                                                int idx = pq.top(); //O(1)

                                                                                                                            if(idxToNum[idx] == number) {
                                                                                                                                            return idx;
                                                                                                                                                        }

                                                                                                                                                                    pq.pop(); //O(log(n))
                                                                                                                                                                            }

                                                                                                                                                                                    return -1;
        
  
    

        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */