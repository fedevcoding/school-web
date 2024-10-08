// Page elements

const formattedText = document.getElementById("formatted-text");
const fontSize = document.getElementById("font-size");
const applyFontSize = document.getElementById("apply-font-size");
const colorPicker = document.getElementById("text-color");
const styleCheckboxes = document.querySelectorAll(".stiles input[type=checkbox]");

// Event listeners
applyFontSize.addEventListener("click", () => {
  formattedText.style.fontSize = fontSize.value + "px";
});

colorPicker.addEventListener("input", () => {
  formattedText.style.color = colorPicker.value;
});

styleCheckboxes.forEach(checkbox => {
  checkbox.addEventListener("change", () => {
    formattedText.style[checkbox.getAttribute("data-style")] = checkbox.checked ? checkbox.value : "unset";
  });
});
