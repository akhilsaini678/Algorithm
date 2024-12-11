class KthLargest {
public:
    vector<int> heap;
    int k;
    void insert(int val){
        heap.push_back(val);
        int size = heap.size();
        for(int index = size-1;index!=0&&heap[(index-1)/2]>heap[index];){
            swap(heap[(index-1)/2],heap[index]);
            index = (index-1)/2;    
        }
    }

    void heapify(int index){
        int smallest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<heap.size()&&heap[left]<heap[smallest]) smallest = left;
        if(right<heap.size()&&heap[right]<heap[smallest]) smallest = right;
        if(smallest==index) return;
        swap(heap[smallest],heap[index]);
        heapify(smallest);
    }

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<nums.size();i++){
            if(heap.size()<k){
                insert(nums[i]);
            } else if(nums[i]>heap[0]){
                heap[0] = nums[i];
                heapify(0);
            }
        }
    }
    
    int add(int val) {
        if (heap.size() < k) {
           insert(val); 
        }
        else if(val>heap[0]){ 
            heap[0] = val;
            heapify(0);
        }
        return heap[0];
    }
};