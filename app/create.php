<?php include 'includes/db.php'; ?>
<?php include 'partials/header.php'; ?>

<?php
$message = '';
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $age = $_POST['age'];

    $sql = "INSERT INTO users (name, email, age) VALUES ('$name', '$email', '$age')";
    if ($conn->query($sql) === TRUE) {
        $message = "<div class='message success'>New record created successfully</div>";
    } else {
        $message = "<div class='message error'>Error: " . $sql . "<br>" . $conn->error . "</div>";
    }
}
?>

<form method="post" action="create.php">
    <h2>Create User</h2>
    <?php echo $message; ?>
    <label>Name:</label>
    <input type="text" name="name" required>
    <label>Email:</label>
    <input type="email" name="email" required>
    <label>Age:</label>
    <input type="number" name="age" required>
    <button type="submit">Create</button>
</form>

<?php include 'partials/footer.php'; ?>
