
#include <iostream>
#include <vector>

using std::vector;
void quicksort(vector<int>& V,  vector<int>& W, int l, int hi);
int partition(vector<int>& V, vector<int>& W, int l, int hi);
void swap(int* a, int* b);  

void quicksort(vector<int>& V,  vector<int>& W, int l, int hi){
	if(l<hi){
		int p = partition(V, W, l, hi);
		quicksort(V, W, l, p-1);
		quicksort(V, W, p+1, hi);
  }
}

int partition(vector<int>& V, vector<int>& W, int l, int hi){  
	float Pivot = ((float) V[hi]/W[hi]);
	int i = l;
	for (int j=l; j<hi; j++){
		if ( ((float)V[j]/W[j]) < Pivot){
			swap(&V[i], &V[j]);
      swap(&W[i], &W[j]);
      i++;
		}
	}
	swap(&V[i], &V[hi]);
  swap(&W[i], &W[hi]);
	return i;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values) {
  double value = 0.0;
  int n = weights.size();
  //quicksort(values, weights, 0, n-1);
  for(int i=0; i<n; ++i){
    std::cout << values[i] << ' ' << weights [i] << ' ' << ((float) values[i]/weights[i]) << '\n';
  }
  for (int i=n-1; i>=0 && capacity>0; --i) {
    if (weights[i] <= capacity){
      value += values[i];
      capacity -= weights[i];
    }
    else {
      value += ((double)values[i]/weights[i])*capacity;
      capacity = 0;
    }
  }
  return value;
}

int main() 
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    if ( (i >=1) && (((float)values[i]/weights[i]) > ((float) values[i-1]/weights[i-1])) ){
      swap(&values[i], &values[i-1]);
      swap(&weights[i], &weights[i-1]);
    } // Tranh' worst case
  }
  quicksort(values, weights, 0, n-1);

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
