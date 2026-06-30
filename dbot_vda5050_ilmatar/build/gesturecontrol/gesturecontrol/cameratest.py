import cv2

def test_camera(index):
    cap = cv2.VideoCapture(index)
    ret, frame = cap.read()
    if ret:
        cv2.imshow(f'Camera Test on /dev/video{index}', frame)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
    else:
        print(f"Failed to get video from /dev/video{index}")
    cap.release()

for i in range(4,5):  # Assuming 6 device nodes as per your list
    test_camera(i)