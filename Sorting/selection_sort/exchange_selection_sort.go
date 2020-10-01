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

func selectionSort(n int, arr []int) {
  // O(n^2) time
  for j := 0; j < n; j++ {
    swap_idx := j
    for i := j + 1; i < n; i++ {
      if arr[i] < arr[swap_idx] {
        swap_idx = i
      }
    }
    key := arr[j]
    arr[j] = arr[swap_idx]
    arr[swap_idx] = key
    fmt.Printf("Step %d: %v\n", j+1, arr)
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
  selectionSort(n, arr)
  fmt.Println("After:", arr)
}
