//Задание 1
function myFunction(a, b) {
    if (a % 2 === 0) {
        console.log(a * b);
    } else {
        console.log(a + b);
    }
}


myFunction(5, 2); // Вывод: 7


//Задание 2
function findQuarter(x, y) {
    if (x === 0 || y === 0) {
        console.log("Точка принадлежит оси координат");
    } else if (x > 0 && y > 0) {
        console.log("Точка принадлежит 2-й четверти");
    } else if (x < 0 && y > 0) {
        console.log("Точка принадлежит 1-й четверти");
    } else if (x < 0 && y < 0) {
        console.log("Точка принадлежит 3-й четверти");
    } else if (x > 0 && y < 0) {
        console.log("Точка принадлежит 4-й четверти");
    }
}


findQuarter(-2, 4); // Вывод: "Точка принадлежит 1-й четверти"
findQuarter(0, 3);  // Вывод: "Точка принадлежит оси координат"


//Задание 3
function sumPositive(arr) {
    let sum = 0;
   
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
   
    console.log(sum);
}


sumPositive([-2, 4, 7, -9, 2]); // Вывод: 13




//Задание 4
function findMax(a, b, c) {
    const product = a * b * c;
    const sum = a + b + c;
   
    if (product > sum) {
        console.log(product + 3);
    } else {
        console.log(sum + 3);
    }
}


findMax(1, 2, 1); // Вывод: 7
findMax(3, 4, 1); // Вывод: 15