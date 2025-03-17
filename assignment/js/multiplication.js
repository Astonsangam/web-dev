function multiplicationTable() {
    let num = document.getElementById("multiplicationInput").value;
    let result = "";
    for (let i = 1; i <= 10; i++) {
        result += `${num} x ${i} = ${num * i}\n`;
    }
    console.log(result)
    document.getElementById("multiplicationResult").textContent = result;
}
