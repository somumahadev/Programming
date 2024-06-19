document.addEventListener("DOMContentLoaded", function() {
    const form = document.querySelector("form");
    const nameInput = form.querySelector("input[name='name']");
    const emailInput = form.querySelector("input[name='email']");
    const ageInput = form.querySelector("input[name='age']");

    form.addEventListener("submit", function(event) {
        let valid = true;
        
        if (nameInput.value.trim() === "") {
            valid = false;
            alert("Name is required.");
        }

        if (emailInput.value.trim() === "") {
            valid = false;
            alert("Email is required.");
        } else if (!validateEmail(emailInput.value)) {
            valid = false;
            alert("Please enter a valid email address.");
        }

        if (ageInput.value.trim() === "" || isNaN(ageInput.value) || ageInput.value <= 0) {
            valid = false;
            alert("Please enter a valid age.");
        }

        if (!valid) {
            event.preventDefault();
        }
    });

    function validateEmail(email) {
        const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        return re.test(email);
    }
});
