function checkEvenOdd() {
    let num = document.getElementById("evenOddInput").value;
    let result = num % 2 === 0 ? `${num} is an even number.` : `${num} is an odd number.`;
    console.log(result)
    document.getElementById("evenOddResult").textContent = result;
}
