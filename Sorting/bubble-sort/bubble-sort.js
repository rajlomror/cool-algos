// Bubble sort algorithm.<br>
// @param {Array} array Input array.
// @param {Function} cmp Optional. A function that defines an
// alternative sort order. The function should return a negative,
// zero, or positive value, depending on the arguments.
// @return {Array} Sorted array.

module.exports = {
  bubbleSort: (array, customCompare) => {
    let compare = (a, b) => a - b;
    compare = customCompare || compare;
    var tmp;
    for (var i = 0; i < array.length - 1; i += 1) {
      var swapCount = 0;
      for (var j = 0; j < array.length - 1 - i; j += 1) {
        if (compare(array[j], array[j + 1]) > 0) {
          tmp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = tmp;
          swapCount += 1;
        }
      }
      if (swapCount === 0) {
        break;
      }
    }
    return array;
  },
};
