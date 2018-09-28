<?php
// 快速排序 https://zh.wikipedia.org/wiki/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F#PHP
function quickSort($arr) {
    $len = count($arr);
    if ($len <=1) return $arr;
    $left = $right = [];
    $mid = $arr[0];
    for ($i = 1; $i < $len; $i++) {
        if ($arr[$i] < $mid) {
            $left[] = $arr[$i];
        } else {
            $right[] = $arr[$i];
        }
    }
    return array_merge(quickSort($left),(array)$mid, quickSort($right));
}
$arr = [1,4,6,12,6,5,2,3];
$test = quickSort($arr);
print_r($test);
