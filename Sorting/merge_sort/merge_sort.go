package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func mergeSort(n int, arr []int) {
  mergeSortRecursive(arr, 0, n)
}

func mergeSortRecursive(arr []int, start, end int) {
  // start is inclusive, end is exclusive
  if end - start == 1 {
    return
  }

  if end - start == 2 {
    if arr[start] > arr[end - 1] {
      arr[start], arr[end - 1] = arr[end - 1], arr[start]
    }
  } else {
    mid := (start + end) / 2
    mergeSortRecursive(arr, start, mid)
    mergeSortRecursive(arr, mid, end)

    sortedA := make([]int, mid - start)
    sortedB := make([]int, end - mid)

    for i := 0; i < len(sortedA); i++ {
      sortedA[i] = arr[start + i]
    }
    for i := 0; i < len(sortedB); i++ {
      sortedB[i] = arr[mid + i]
    }

    p, q := 0, 0
    n1, n2 := len(sortedA), len(sortedB)
    for i := start; i < end; i++ {
      if q >= n2 || (p < n1 && sortedA[p] < sortedB[q]) {
        arr[i] = sortedA[p]
        p++
      } else {
        arr[i] = sortedB[q]
        q++
      }
    }
  }
}

func readArray(reader *bufio.Reader, n int) []int {
  str, _, err := reader.ReadLine()
  if err != nil {
    panic(err)
  }

  temp := strings.Split(string(str), " ")
  arr := make([]int, n)

  for i := 0; i < n; i++ {
    arr[i], err = strconv.Atoi(temp[i])
    if err != nil {
      panic(err)
    }
  }

  return arr
}

func main() {
  defer writer.Flush()

  var n int
  fmt.Fscanf(reader, "%d\n", &n)
  arr := readArray(reader, n)

  fmt.Println("Before:", arr)
  mergeSort(n, arr)
  fmt.Println("After:", arr)
}
