<?php
function sort($arr) {
    if (count($arr) <= 1) {
        return $arr;
    }
    $key = $arr[0];
    $leftArr  = array();
    $rightArr = array();
    $len = count($arr);
    for ($i = 1; $i < $len; $i++) {
        if ($arr[$i] > $key) {
            $riginArr[] = $arr[$i];
        } else {
            $leftArr[]  = $arr[$i];
        }
    } 
    $leftArr  = sort($leftArr);
    $riginArr = sort($righrArr);
    return array_merge($leftArr, array($key), $rightArr);
}
?>
