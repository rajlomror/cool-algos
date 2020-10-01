// Insertion sort algorithm.<br>
// @param {Array} array Input array.
// @param {Function} cmp Optional. A function that defines an
// alternative sort order. The function must return a negative,
// zero, or positive value.
// @return {Array} Sorted array.

module.exports = {
  insertionSort: (array, customCompare) => {
    let compare = (a, b) => a - b;
    compare = customCompare || compare;
    var current;
    var j;
    for (var i = 1; i < array.length; i += 1) {
      current = array[i];
      j = i - 1;
      while (j >= 0 && compare(array[j], current) > 0) {
        array[j + 1] = array[j];
        j -= 1;
      }
      array[j + 1] = current;
    }
    return array;
  },
};
