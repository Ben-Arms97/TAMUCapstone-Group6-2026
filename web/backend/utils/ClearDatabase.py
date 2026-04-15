import threading
import time
from sqlalchemy import text

def start_truncate_job(app, db, interval):
    def truncate_loop():
        while True:
            time.sleep(interval)

            try:
                with app.app_context():
                    db.session.execute(
                        text("TRUNCATE TABLE event RESTART IDENTITY;"))
                    db.session.commit()
                    print("Event table truncated")
            except Exception as e:
                with app.app_context():
                    db.session.rollback()
                print(f"Truncate failed: {e}")

    thread = threading.Thread(target=truncate_loop, daemon=True)
    thread.start()
