<?php include 'includes/db.php'; ?>

<?php
$id = $_GET['id'];
$sql = "DELETE FROM users WHERE id=$id";

if ($conn->query($sql) === TRUE) {
    echo "<p>Record deleted successfully</p>";
} else {
    echo "<p>Error: " . $sql . "<br>" . $conn->error . "</p>";
}
?>

<a href="read.php">Back to User List</a>
