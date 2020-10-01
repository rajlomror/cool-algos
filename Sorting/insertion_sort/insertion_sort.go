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

func insertionSort(n int, arr []int) {
  for j := 0; j < n; j++ {
    // left to right 0:-->N
    var val = arr[j]
    i := j - 1
    for ; i >= 0 && arr[i] > val; i-- {
      // Scanning backward into the sorted portion A[0..j]
      arr[i + 1] = arr[i]
    }
    arr[i + 1] = val
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
  insertionSort(n, arr)
  fmt.Println("After:", arr)
}
