from flask_sqlalchemy import SQLAlchemy
from sqlalchemy.dialects.postgresql import UUID
from sqlalchemy import BigInteger, func

import uuid

db = SQLAlchemy()

class Event(db.Model):
    id = db.Column(UUID, primary_key=True, default=lambda: str(uuid.uuid4()))
    angle = db.Column(db.Float(), nullable=False)
    battery = db.Column(db.Float(), nullable=False)
    timestamp = db.Column(
        BigInteger,
        nullable=False,
        server_default=(func.extract("epoch", func.now()) * 1000)
    )