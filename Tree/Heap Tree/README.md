<h1>Complete BT ?</h1>
<h2>Binary tree where all levels except the last are completely filled orelse if any levels are partially filled then all nodes in that level should be as left as possible.</h2>
<h1>Heap Tree :</h1>
<h2>A Heap is a special Tree-based data structure in which the tree is a complete binary tree.</h2>
<h1>It follows the Heap Property –</h1>
<h2>Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.</h2>
<h2>Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.</h2>
<img src="https://simplesnippets.tech/wp-content/uploads/2021/04/heap-data-structure-with-program-code.jpg">
<h1>WAYS OF IMPLEMENTATION :</h1>
<img src="https://i.ibb.co/S7KWB3Q/HEAPdS.png">
*
<h2>NOTE: We are going to continue with **Min Heap** implementations. For Max Heap, every approach will be as simillar as MinHeap with some small changes you yourself will know the changes once you complete MinHeap implementations.</h2>
<h1>Functions Overview in MinHeap</h1>

<h2> 1. Insertion in MinHeap</h1>

<h2> 2. Display Heap</h2>

<h2>3. Height of Heap Tree</h2>

<h2> 4. Current Heap Size</h2>

<h2> 5. minExtract()</h2>

<h2>- Heapify</h2>

<h2> 6. minDeleteKey()</h2>

<h2>- DecreaseKey()</h2>
<h2> 7. Heap Sort</h2>
<h1>1 - Insert an Element</h1>
<h3>Video reference : https://www.youtube.com/watch?v=5l3n3HFgljg
</h3>

```cpp
int parent(int i){
        return(i-1)/2;//return the parent Node
    }
    int left(int i){
        return(2*i+1);//return left child Node
    }
    int right(int i){
        return(2*i+2);//return right child node
    }
    void insertKey(int k){
        if(heap_size==capacity){
            cout<<"\nOverflow: Could not insert key\n";
            return;
        }
        //First Insert the new key at the end
        heap_size++;
        int i=heap_size-1;
        harr[i]=k;
        //Fix the min heap property if it is violated
        while(i!=0 && harr[parent(i)]>harr[i]){
            swap(harr[i],harr[parent(i)]);
            i=parent(i);
        }
    }
```
<h1>2. Display Heap</h1>

```cpp
void PrintArray(){
        for(int i=0;i<heap_size;i++)
            cout<<harr[i]<<" ";
        cout<<endl;
    }
```
<h1>3. Height of Heap Tree </h1>

```cpp
int height(){
        return ceil(log2(heap_size+1))-1;
    }
```
