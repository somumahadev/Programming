<?php include 'includes/db.php'; ?>
<?php include 'partials/header.php'; ?>

<?php
$id = $_GET['id'];
$sql = "SELECT * FROM users WHERE id=$id";
$result = $conn->query($sql);
$row = $result->fetch_assoc();

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $age = $_POST['age'];

    $sql = "UPDATE users SET name='$name', email='$email', age='$age' WHERE id=$id";
    if ($conn->query($sql) === TRUE) {
        echo "<p>Record updated successfully</p>";
    } else {
        echo "<p>Error: " . $sql . "<br>" . $conn->error . "</p>";
    }
}
?>

<form method="post" action="update.php?id=<?php echo $id; ?>">
    <label>Name:</label>
    <input type="text" name="name" value="<?php echo $row['name']; ?>" required>
    <label>Email:</label>
    <input type="email" name="email" value="<?php echo $row['email']; ?>" required>
    <label>Age:</label>
    <input type="number" name="age" value="<?php echo $row['age']; ?>" required>
    <button type="submit">Update</button>
</form>

<?php include 'partials/footer.php'; ?>
