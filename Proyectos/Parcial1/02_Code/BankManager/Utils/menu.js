document.addEventListener("DOMContentLoaded", () => {
  const contentDiv = document.getElementById("main-content");

  const contentMap = {
    "estibi": "<h2>Estibi</h2><p>Responsable del área de sistemas y soporte técnico.</p>",
    "richi": "<h2>Richi</h2><p>Encargado de atención al cliente y servicios personalizados.</p>",
    "angelito": "<h2>Angelito</h2><p>Coordinador de operaciones bancarias.</p>",
    "que-es-banco": "<h2>¿Qué es \"El banco\"?</h2><p>Somos un programa que simula un cajero automático, aquí podrás crear cuentas, hacer movimientos bancarios, entre otras cosas.</p>",
    "crear-usuario": "<h2>Crear Usuario</h2><p>Para crear un usuario requerimos tu nombre y apellido, correo electrónico, cédula.</p>",
    "nuevos-usuarios": "<h2>Nuevos Usuarios</h2><p>Si eres nuevo, crea una cuenta bancaria, si no lo eres, inicia sesión con tu cuenta.</p>",
    "crear-cuentas": "<h2>Crear Cuentas</h2><p>Para crear cuentas, cuando ejecutes el programa, selecciona la opción de creaar una cuenta con el menú de cursores.</p>",
    "depositos": "<h2>Depósitos</h2><p>Aquí podrás añadir dinero a tu cuenta, o enviar dinero a tus amigos.</p>",
    "retiros": "<h2>Retiros</h2><p>Con esta opción podrás retirar dinero del cajero.</p>",
    "crear-backup": "<h2>Crear Backup</h2><p>Genera una copia de seguridad, que te permite guardar un respaldo de los datos del sistema.</p>",
    "usar-backup": "<h2>Usar Backup</h2><p>Selecciona y restaura una copia de seguridad existente.</p>"
  };

  Object.entries(contentMap).forEach(([id, html]) => {
    const el = document.getElementById(id);
    if (el) {
      el.addEventListener("click", e => {
        e.preventDefault();
        contentDiv.innerHTML = html;
      });
    }
  });
});
