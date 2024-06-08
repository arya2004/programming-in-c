// File Name: showNotification.js
// Description: Displays a notification.

function showNotification() {
    let title = "I love Educative.io";
    let icon = 'https://homepages.cae.wisc.edu/~ece533/images/zelda.png'; // Replace with a smaller icon
    let body = "Message to be displayed";
  
    let notification = new Notification(title, { body, icon });
  
    notification.onclick = () => {
      notification.close();
      window.parent.focus();
    }
  }
  
  showNotification();
  